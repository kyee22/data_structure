#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
int used[100],num[100],n;
void solve(int k){
    if(k==n+1){
        for(int i=1;i<=n;i++){
            printf(i==n?"%d\n":"%d ",num[i]);
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
            num[k]=i;
            used[i]=1;
            solve(k+1);
            used[i]=0;
        }
    }
}
int main()
{
    scanf("%d",&n);
    solve(1);
	return 0;
}
