#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

struct path{
    int path[1000];
    int num;
}paths[10000];int total;

int pass[1000];
typedef struct node1{
    int pathID;
    int adjvex;
    int weight;
    struct node1 *next;
}edge,*edgePtr;

typedef struct node2{
    int info;
    edgePtr list;
}ver,*verPtr;

int visited[10000],src,dest;
ver Graph[10000];


edgePtr insert(edgePtr list,int id,int x);
void DFS(int i,int level);

int n,e,id,a,b;


int cmp(const void *p,const void *q);
int main(){
    int n,e,id,a,b;
    scanf("%d%d",&n,&e);
    for(int i=0;i<e;i++){
        scanf("%d%d%d",&id,&a,&b);
        Graph[a].list=insert(Graph[a].list,id,b);
        Graph[b].list=insert(Graph[b].list,id,a);
    }

    src=0,dest=n-1;
    visited[src]=1;

    DFS(src,0);

    qsort(paths,total,sizeof(struct path),cmp);

    for(int i=0;i<total;i++){
        for(int j=0;j<paths[i].num;j++){
            printf((j==paths[i].num-1)?"%d\n":"%d ",paths[i].path[j]);
        }
    }
    return 0;
}
edgePtr insert(edgePtr list,int id,int x){
    edgePtr cur,new=(edgePtr)malloc(sizeof(edge));
    new->adjvex=x;new->pathID=id;new->weight=1;new->next=NULL;

    if(list==NULL){
        return new;
    }
    else{
        for(cur=list;cur->next;cur=cur->next);//插入到表尾
        cur->next=new;
        return list;
    }
    
}
int cmp(const void *p,const void *q){
    struct path *a=(struct path *)p;
    struct path *b=(struct path *)q;
    int i=0;
    while(1){
        if(a->path[i]!=b->path[i])return a->path[i]-b->path[i];
        i++;
    }
}

void DFS(int i,int level){
    if(i==dest){
        // printf("*%d %d %d %d\n",pass[0],pass[1],pass[2],pass[3]);
        // for(int j=0;j<level;j++){
        //     paths[total].path[j]=pass[j];
        //     // printf((j==n-2)?"%d\n":"%d ",pass[j]);        
        // }
        memcpy(paths[total].path,pass,sizeof(pass));
        // puts(paths[total].path);
        paths[total].num=level;
        total++;
        return;
    }
    else{
        edgePtr cur;
        for(cur=Graph[i].list;cur;cur=cur->next){
            if(!visited[cur->adjvex]){
                pass[level]=cur->pathID;
                visited[cur->adjvex]=1;
                DFS(cur->adjvex,level+1);
                visited[cur->adjvex]=0;//回溯
            }

        }
    }
}