#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
struct node {
    int data;
    struct node *next;
};
int cmp(const void *p,const void *q){
    int *a=(int *)p;
    int *b=(int *)q;
    return *a-*b;
}
int main(){
    int n,data,lst[100000],pos=0;
    struct node *list=NULL, *p,*q;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&lst[i]);
        q=(struct node*)malloc(sizeof(struct node));
        q->next=NULL;
        q->data=lst[i];
        if(list==NULL){
            list=p=q;
        }
        else{
            p->next=q;
            p=p->next;
        }
    }
    p->next=list;
    qsort(lst,n,sizeof(int),cmp);

    struct node *cur=list,*pre=p;
    while(n){
        if(cur->data==lst[pos]){
            printf("%d\n",cur->data);

            pre->next=cur->next;
            free(cur);
            cur=pre->next;
            n--;
            pos++;
        }
        else{
            printf("%d ",cur->data);

            pre=cur,cur=cur->next;
        }
    }
    return 0;
}