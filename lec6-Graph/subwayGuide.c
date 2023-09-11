#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
#define INFI 9999999
#define maxsize 1000
struct station{
    char staName[100];
    int isChange;
}staList[maxsize];

struct edge{
    int weight;
    int lineID;
}weight[maxsize][maxsize];

int pre[maxsize];//(i,pre[i])构成一条边,而且pre[i]是i的前驱节点

int lineNum,//地铁线路数
    lineID,//地铁线路编号
    staNum,//每一条地铁线路的地铁站数
    ischange;
char staName[100];

int vNum;//初始为0,并随着staList的更新而作为下标更新
int search(char s[]);//在staList寻找:找到,返回下标;未找到,返回-1
void Dijkstra(int src,int dest);

struct ans{
    char staName[100];
    int step;
    int lineID;
}stack[10000];int top=0;
int main(){

    /*   初始化图   */
    for(int i=0;i<maxsize;i++)
    for(int j=0;j<maxsize;j++){
        weight[i][j].weight=INFI;
        weight[j][i].weight=INFI;
    }
  
    FILE *in=fopen("bgstations.txt","r");
    fscanf(in,"%d",&lineNum);

    for(int i=0;i<lineNum;i++){
        fscanf(in,"%d%d",&lineID,&staNum);
        int v1=-1,v2;
        for(int j=0;j<staNum;j++){
            fscanf(in,"%s%d",staName,&ischange);
            v2=search(staName);
            if(v2==-1){//staName首次出现
                strcpy(staList[vNum].staName,staName);
                staList[vNum].isChange=ischange;
                v2=vNum;
                if(v1!=-1){
                    weight[v1][v2].lineID=lineID;
                    weight[v2][v1].lineID=lineID;
                    weight[v1][v2].weight=1;
                    weight[v2][v1].weight=1;
                }
                v1=v2;
                vNum++;
            }
            else{//staName**重复**出现
                if(v1!=-1){
                    weight[v1][v2].lineID=lineID;
                    weight[v2][v1].lineID=lineID;
                    weight[v1][v2].weight=1;
                    weight[v2][v1].weight=1;
                }
                v1=v2;
            }
        }
    }
    int src,dest;
    char begin[100],end[100];
    scanf("%s%s",begin,end);
    src=search(begin);
    dest=search(end);

    Dijkstra(src,dest);
    int cnt=0,last_lineID=weight[dest][pre[dest]].lineID,this_lineID;
    for(int i=dest;;i=pre[i]){
        this_lineID=weight[i][pre[i]].lineID;
        if(this_lineID!=last_lineID||i==src){
            stack[top].lineID=last_lineID;
            stack[top].step=cnt;
            strcpy(stack[top].staName,staList[i].staName);
            top++;

            cnt=1;
        }
        else{
            cnt++;
        }
        last_lineID=this_lineID;
        if(i==src)break;
    }
    for(int i=top-1;i>=0;i--){
        printf("%s-%d(%d)-",stack[i].staName,stack[i].lineID,stack[i].step);
    }
    printf("%s",staList[dest].staName);

    return 0;
}
int search(char s[]){
    int i;
    for(i=0;i<vNum;i++){
        if(strcmp(s,staList[i].staName)==0){
            return i;
        }
    }
    return -1;
}
void Dijkstra(int src,int dest){
    int i,j,v,min,minWeight[maxsize]={0},wfound[maxsize]={0};//用于标记从src到相应顶点是否找到最短路径，0未找到，1找到
    for(i=0;i<vNum;i++){
        minWeight[i]=weight[src][i].weight;
        pre[i]=src;
    }//初始化
    minWeight[src]=0;
    wfound[src]=1;
    for(i=0;i<vNum-1;i++){//迭代vNum-1次
        min=INFI;
        for(j=0;j<vNum;j++)//找到未标记的最小权重值顶点
            if(!wfound[j]&&(minWeight[j]<min)){
                v=j;
                min=minWeight[v];
            }
        wfound[v]=1;//标记该顶点为已找到最短路径
        if(v==dest)return;
        for(j=0;j<vNum;j++)//找到未标记顶点且其权值大于v的权值+(v,j)的权值，更新其权值
            if(!wfound[j]&&(min+weight[v][j].weight<minWeight[j])){
                minWeight[j]=min+weight[v][j].weight;
                pre[j]=v;//记录前驱顶点
            }
    }  
}