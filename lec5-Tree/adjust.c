#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

struct MTnode{
    struct MTnode *children[5];
};

struct depar{
    int id;
    int vol;
};

struct MTnode Node[10000]; /*  编号与下标下同, 这样可以快速访问目标编号的节点  */
struct depar infoList[10000];
int idList[10000],cnt;

int cmp(const void *p,const void *q){
    struct depar *a=(struct depar *)p;
    struct depar *b=(struct depar *)q;
    if(a->vol!=b->vol)return b->vol-a->vol;
    else return a->id-b->id;
}

void visit(struct MTnode *p){
    if(p->children[0]==NULL&&p->children[1]==NULL&&p->children[2]==NULL){
        idList[cnt++]=(p-Node);
    }
}
    
void layerOrder(struct MTnode *t){
    struct MTnode *Queue[10000],*p;
    int front=0,rear=0;
    Queue[0]=t;
    while(front<=rear){
        p=Queue[front++];
        visit(p);
        int i=0;
        while(p->children[i]!=NULL){
            Queue[++rear]=p->children[i];
            i++;
        }
        
    }
}
int main(){

    int parent,son;

    while(1){
        scanf("%d",&parent);
        if(parent==-1)break;

        int i=0;
        while(1){
            scanf("%d",&son);
            if(son==-1)break;

            Node[parent].children[i++]=&Node[son];
        }
    }
   
    layerOrder(&Node[100]);


    for(int i=0;i<cnt;i++){
        scanf("%d%d",&infoList[i].id,&infoList[i].vol);
    }
    
    qsort(infoList,cnt,sizeof(struct depar),cmp);
    for(int i=0;i<cnt;i++){
        printf("%d->%d\n",infoList[i].id,idList[i]);
    }
    return 0;
}