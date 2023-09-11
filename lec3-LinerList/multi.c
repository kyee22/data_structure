#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
#define maxsize 10000000
char s1[maxsize],s2[maxsize],ch=' ';
LL ans_a[maxsize],ans_n[maxsize],cnt,x,y;
struct formula{
    LL pos;
    LL a;
    LL n;
    struct  formula *next;
};

int main(){
    struct formula *head_1=NULL,*head_2=NULL,*tail_1,*tail_2,*p_mom=NULL,*q_mom=NULL,*p_tmp=NULL,*q_tmp=NULL;
    struct formula *p=NULL,*q=NULL,*m=NULL,*n=NULL,*pretail_1=NULL,*pretail_2=NULL;
    /*  create linked list  */
    for(LL i=0;i<1000000;i++){
        q=(struct formula*)malloc(sizeof(struct formula));
        q->next=NULL;
        if(head_1==NULL){
            head_1=p=q;
        }
        else{
            p->next=q;
            p=p->next;
        }
    }
    tail_1=head_1;
    for(LL i=0;i<1000000;i++){
        n=(struct formula*)malloc(sizeof(struct formula));
        n->next=NULL;
        if(head_2==NULL){
            head_2=m=n;
        }
        else{
            m->next=n;
            m=m->next;
        }
    }
    tail_2=head_2;
    /*   input  */
    while(ch!='\n'){
        LL tmp1,tmp2;
        scanf("%lld%lld%c",&tmp1,&tmp2,&ch);
        tail_1->a=tmp1;
        tail_1->n=tmp2;
        tail_1->pos=y++;

        pretail_1=tail_1;
        tail_1=tail_1->next;

    }
    ch=' ';
    while(ch!='\n'){
        LL tmp1,tmp2;
        scanf("%lld%lld%c",&tmp1,&tmp2,&ch);
        tail_2->a=tmp1;
        tail_2->n=tmp2;
        tail_2->pos=y++;

        pretail_2=tail_2;
        tail_2=tail_2->next;

    }

    tail_1=pretail_1;
    tail_2=pretail_2;

    p_mom=head_1,q_mom=head_2;
    p_tmp=p_mom,q_tmp=q_mom;
    while(1){
        LL move_mode=0;

        // boundary
        if(p_mom==tail_1&&q_mom==tail_2){
            ans_a[cnt]=p_mom->a*q_mom->a;
            ans_n[cnt++]=p_mom->n+q_mom->n;         
            break;   
        }


        // get ans
        if(p_tmp==p_mom&&q_tmp==q_mom){
            ans_a[cnt]=p_tmp->a*q_tmp->a;
            ans_n[cnt++]=p_tmp->n+q_tmp->n;
            move_mode=1;//p_tmp和q_tmp都往后移动
        }
        else{
            if(p_tmp->pos>p_mom->pos&&q_mom->pos==q_tmp->pos){
                if(q_tmp==tail_2){
                    while(p_mom!=p_tmp){
                        p_mom=p_mom->next;
                    }
                    continue;
                }
                q_tmp=q_tmp->next;
            }
            else if(q_tmp->pos>q_mom->pos&&p_mom->pos==p_tmp->pos){
                if(p_tmp==tail_1){
                    while(q_mom!=q_tmp){
                        q_mom=q_mom->next;
                    }
                    continue;
                }
                p_tmp=p_tmp->next;
            }


            if((p_mom->n+q_tmp->n)>(q_mom->n+p_tmp->n)){
                ans_a[cnt]=p_mom->a*q_tmp->a;
                ans_n[cnt++]=p_mom->n+q_tmp->n;
                move_mode=2;//q_tmp往后移动
            }
            else if((p_mom->n+q_tmp->n)<(q_mom->n+p_tmp->n)){
                ans_a[cnt]=q_mom->a*p_tmp->a;
                ans_n[cnt++]=q_mom->n+p_tmp->n;
                move_mode=3;//p_tmp往后移动
            }
            else if((p_mom->n+q_tmp->n)==(q_mom->n+p_tmp->n)){
                ans_a[cnt]=(p_mom->a*q_tmp->a)+(q_mom->a*p_tmp->a);
                ans_n[cnt++]=(p_mom->n+q_tmp->n);
                move_mode=1;//p_tmp和q_tmp都往后移动
            }
        }
        // move and fresh the pointers
        if(move_mode==1){
            if(p_tmp==tail_1&&q_tmp==tail_2){
                p_mom=p_mom->next;
                q_mom=q_mom->next;

                p_tmp=p_mom;
                q_tmp=q_mom;
            }
            else if(p_tmp==tail_1&&q_tmp!=tail_2){
                q_mom=q_mom->next;

                p_tmp=p_mom;
                q_tmp=q_tmp->next;

            }
            else if(p_tmp!=tail_1&&q_tmp==tail_2){
                p_mom=p_mom->next;

                q_tmp=q_mom;
                p_tmp=p_tmp->next;
            }
            else{
                p_tmp=p_tmp->next;
                q_tmp=q_tmp->next;
            }
        }
        else if(move_mode==2){
            if(q_tmp==tail_2&&p_mom!=tail_1){
                p_mom=p_mom->next;
                q_tmp=q_mom;
            }
            else{
                q_tmp=q_tmp->next;
            }
        }
        else if(move_mode==3){
            if(p_tmp==tail_1&&q_mom!=tail_2){
                q_mom=q_mom->next;
                p_tmp=p_mom;
            }
            else{
                p_tmp=p_tmp->next;
            }
        }
    }
    /*   bubble sort   */
    for(LL i=1;i<cnt;i++){
        for (LL j=0;j<cnt-i;j++){
            if(ans_n[j]<ans_n[j+1]){
                LL tmp=ans_n[j];
                ans_n[j]=ans_n[j+1];
                ans_n[j+1]=tmp;
                tmp=ans_a[j];
                ans_a[j]=ans_a[j+1];
                ans_a[j+1]=tmp;
            }
        }
    }
    for(LL i=0;i<cnt-1;i++){
        if(ans_n[i]==ans_n[i+1]){
            ans_a[i+1]+=ans_a[i];
            ans_a[i]=0;
        }
    }
    for(LL i=0;i<cnt;i++){
        if(ans_a[i]!=0){
            printf("%lld %lld ",ans_a[i],ans_n[i]);
        }
    }
    return 0;
}
