#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
int rpt_cnt[200],pos[200],pos_min=20000;
int i,flag=0;
char c,ans,s[20000];
int main(){
    gets(s);
    while((c=s[i++])!='\0'){
        if(rpt_cnt[c]==0){
            pos[c]=i;
        }
        rpt_cnt[c]++;
    }
    for(char x='a';x<='z';x++){
        // printf("%c %d %d\n",x,rpt_cnt[x],pos[x]);
        if(rpt_cnt[x]!=1){
            continue;
        }
        if(pos[x]<pos_min){
            pos_min=pos[x];
            ans=x;
            flag=1;
        }
    }
    if(flag)printf("%c\n",ans);
    else printf("no\n");
    return 0;
}