#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

int n,m,num[100],used[100],cnt;

void permutate_m(int k){
    if(k==m+1){
        for(int i=1;i<=m;i++)
            printf(i==m?"%d\n":"%d ",num[i]);
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
            used[i]=1;
            num[k]=i;
            permutate_m(k+1);
            used[i]=0;
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    permutate_m(1);
    return 0;
}