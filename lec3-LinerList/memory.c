#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
LL cnt;//the number of blocks
LL is_blank;//最终没有空闲块的标记
struct block{
    LL location;
    LL length;
    struct block *next;
};
int main(){
    scanf("%lld",&cnt);

    /*   create a linked list   */
    struct block *head=NULL,*p,*q;
    for(LL i=0;i<cnt;i++){
        q=(struct block*)malloc(sizeof(struct block));
        q->next=NULL;
        if(head==NULL){
            head=p=q;
        }
        else{
            p->next=q;
            p=p->next;
        }
    }
    p->next=head;
    /*   input 1: fill the list with elements   */
    struct block *cur=head,*last_cur=p;
    
    for(LL i=0;i<cnt;i++){
        scanf("%lld %lld",&cur->location,&cur->length);
        cur=cur->next;
    }

    /*   input 2: distribute memory   */
    cur=head;
    LL len;
    while(~scanf("%lld",&len)){
        if(len==-1){
            break;
        }
        if(is_blank){
            continue;
        }
        /*   寻找优先级：按照题目要求，1)先找和len刚好相等的节点，2)再找大于len且与len相差最小的节点，3)没找到   */
        LL travel_time=0,not_find=0;//travel了cnt次还没找到的话就不再找了
        while(cur->length!=len){
            travel_time++;

            if(travel_time==(cnt+1)){//travel了cnt次还没找到的话就不再找了,且当前cur恰好回到原点
                not_find=1;
                break;
            }

            cur=cur->next;
            last_cur=last_cur->next;
        }
        if(!not_find){//找到和len刚好相等的空间:删除这个节点
            cur=cur->next;

            q=last_cur->next;
            free(q);
            last_cur->next=cur;

            cnt--;
            if(cnt<=0){
                is_blank=1;
            }
        }
        else{//没找到，cur回到原点，再找比len大的空间
            travel_time=0,not_find=0;
            while(cur->length<len){
                travel_time++;

                if(travel_time==(cnt+1)){//travel了cnt次还没找到的话就不再找了
                    not_find=1;
                    break;
                }
                cur=cur->next;
                last_cur=last_cur->next;
            }
            if(!not_find){
                /*   找到比len大的空间，现在正指向第一个比len大的空间节点(这也保证了如果有多个
                     delta_min，找到的也一定是最先出现的那个，从而满足"最佳适应原则")           */
                /*  进一步，确定大于len且与len相差最小的那个空间节点   */
                LL delta,delta_min=cur->length-len;
                for(LL i=0;i<cnt;i++){
                    if(cur->length>len){
                        delta=cur->length-len;
                        if(delta<delta_min){
                            delta_min=delta;
                        }
                    }
                    cur=cur->next;
                    last_cur=last_cur->next;
                }
                for(LL i=0;i<cnt;i++){
                    if(cur->length>len){
                        delta=cur->length-len;
                        if(delta==delta_min){
                            cur->length-=len;
                            break;
                        }
                    }
                    cur=cur->next;
                    last_cur=last_cur->next;
                }
                
            }
            else{//没找到，cur又回到原点
                ;
            }
        }
    }

    /*   output   */
    if(!is_blank){
        for(LL i=0;i<cnt;i++){
            printf("%lld %lld\n",cur->location,cur->length);

            cur=cur->next;
        }
    }
    return 0;
}
