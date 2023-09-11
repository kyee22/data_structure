#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

int G[1000][1000];
int num_of_v,num_of_e,visited[1000],a,b,del_target,queue[1000];
void DFStravel(int n);
void DFS(int i,int n);
void BFStravel(int n);
void BFS(int i,int n);
int main(){
    scanf("%d%d",&num_of_v,&num_of_e);
    for(int i=0;i<num_of_e;i++){
        scanf("%d%d",&a,&b);
        G[a][b]=1;
        G[b][a]=1;
    }
    DFStravel(num_of_v);printf("\n");
    for(int i=0;i<num_of_v;i++)visited[i]=0;
    BFStravel(num_of_v);
     printf("\n");

    scanf("%d",&del_target);
    for(int i=0;i<num_of_v;i++)visited[i]=0;
    visited[del_target]=1;
    DFStravel(num_of_v);
    printf("\n");
    for(int i=0;i<num_of_v;i++)visited[i]=0;
    visited[del_target]=1;
    BFStravel(num_of_v);
     printf("\n");


    return 0;
}
void DFStravel(int n){
    int i;
    
    for(i=0;i<n;i++){
        if(!visited[i])DFS(i,n);
    }    

}
void DFS(int i,int n){
    printf("%d ",i);
    visited[i]=1;
    for(int j=0;j<n;j++){
        if(!visited[j]&&G[i][j]){
            DFS(j,n);
        }
    }
}
void BFStravel(int n){
    int i;
    for(i=0;i<n;i++){
        if(!visited[i])BFS(i,n);
    }   
}
void BFS(int i,int n){
    int front=0,rear=0,tmp;

    visited[front]=1;
    queue[front]=i;

    while(front<=rear){
        tmp=queue[front++];
        printf("%d ",tmp);
        // visited[tmp]=1;

        for(int j=0;j<n;j++){
            if(!visited[j]&&G[tmp][j]){
                visited[j]=1;
                queue[++rear]=j;
            }
        }
    }
}