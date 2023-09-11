#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
#define INFI 999999999
int numV,numE,weight[10000][10000],edge[10000],idMap[10000][10000];//idMap[][]存储(i,j)边的编号

int idList[10000],cnt;//存储id序列(字典序)
int total;//总花费

void Prim(int n,int src,int edge[]){
    int min,minWeight[10000]={0};
    int i,j,k;
    for(int i=0;i<n;i++){
        if(weight[i][src])minWeight[i]=weight[src][i];//与src有边
        else minWeight[i]=INFI;

        edge[i]=src;
    }
    minWeight[src]=0;
    for(int i=1;i<n;i++){//共n-1趟
        min=INFI;
        for(j=0,k=0;j<n;j++){
            if(minWeight[j]!=0&&minWeight[j]<min){
                min=minWeight[j];
                k=j;
            }
        }
        minWeight[k]=0;

        //更新其它节点到生成树的最小距离
        for(j=0;j<n;j++){
            if(minWeight[j]!=0&&weight[j][k]!=0&&weight[k][j]<minWeight[j]){
                minWeight[j]=weight[k][j];
                edge[j]=k;
            }
        }
        // printf("******k:%d |  ",k);
        // for(int i=0;i<numV;i++){
        //     printf(i==(numV-1)?"|| %d %d %d\n":"||%d %d %d",i,edge[i],minWeight[i]);
        // }

        // printf("******\n");
    }
}

int cmp(const void *p,const void *q){
    int *a=(int *)p;
    int *b=(int *)q;
    return (*a)-(*b);
}
int main(){
    scanf("%d%d",&numV,&numE);

    int id,a,b,w;
    for(int i=0;i<numE;i++){
        scanf("%d%d%d%d",&id,&a,&b,&w);

        weight[a][b]=w;
        weight[b][a]=w;

        idMap[a][b]=id;
        idMap[b][a]=id;
    }
    Prim(numV,0,edge);
    for(int idx=1;idx<numV;idx++){//共存储numV-1条边
        total+=weight[idx][edge[idx]];
        idList[cnt++]=idMap[idx][edge[idx]];
    }

    qsort(idList,cnt,sizeof(int),cmp);

    // for(int i=0;i<cnt;i++){
    //     printf(i==(cnt-1)?"%d\n":"%d ",edge[i]);
    // }

    printf("%d\n",total);
    for(int i=0;i<cnt;i++){
        printf(i==(cnt-1)?"%d\n":"%d ",idList[i]);
    }
    return 0;
}