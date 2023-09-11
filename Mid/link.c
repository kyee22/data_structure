#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
struct node{
    int data;
    int cnt;
    struct node *next;
};
int main(){
    int n,a,cmp_num=0,total=1;
    struct node *list=NULL;
    scanf("%d",&n);

    scanf("%d",&a);
    list=(struct node*)malloc(sizeof(struct node));
    list->data=a;
    list->cnt=1;
    list->next=NULL;


    for(int i=1;i<n;i++){
        scanf("%d",&a);

        int find=0;
        struct node *cur=list,*pre=NULL;
        for(;cur!=NULL;pre=cur,cur=cur->next){
            cmp_num++;
            if(cur->data==a){
                find=1;
                break;
            }
        }
        //情况1:未发现
        if(!find){

            struct node *p=(struct node*)malloc(sizeof(struct node));
            p->data=a;
            p->cnt=1;
            p->next=NULL;

            pre->next=p;

            total++;

    //             struct node *tmp=list;
    //     for(int i=0;i<total;i++,tmp=tmp->next){
    //             printf("%d: %d %d\n",i,tmp->data,tmp->cnt);
    // }

        }
 
        //情况2:发现
        else{
            if(cur==list){
                cur->cnt++;
            }
            else{
                pre->next=cur->next;

                cur->next=list;
                list=cur;
                list->cnt++;
            }
            //                 struct node *tmp=list;
            //     for(int i=0;i<total;i++,tmp=tmp->next){
            //             printf("%d: %d %d\n",i,tmp->data,tmp->cnt);
            // }
        }
    }
    struct node *tmp=list;
    for(int i=0;i<5&&i<total;i++,tmp=tmp->next){
        printf("%d %d\n",tmp->data,tmp->cnt);
    }
    printf("%d\n",cmp_num);
    return 0;
}