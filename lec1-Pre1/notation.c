#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

char s[2000000],pre[2000000],post[2000000];

int m,n,flag;

int main()
{
    gets(s);
    int len=strlen(s),i;
    for(i=0;i<len;i++){
        if(s[i]!='.')pre[m++]=s[i];
        else break;
    }
    pre[m]='\0';
    for(i++;i<len;i++)post[n++]=s[i];
    post[n]='\0';
    //case1:
    if(m>1){
        printf("%c.",pre[0]);
        for(int x=1;x<m;x++)printf("%c",pre[x]);
        printf("%s",post);
        printf("e%d\n",m-1);
    }
    else if(m==1){
        //case2:
        if(pre[0]>'0'){
            printf("%se0\n",s);
        }
        //case3:
        else{
            int needle=0;
            for(;needle<n;needle++){
                if(post[needle]!='0'){
                    break;
                }
            }
            int num_of_zero=needle+1;
            printf(needle==n-1?"%c":"%c.",post[needle]);
            for(needle++;needle<n;needle++)printf("%c",post[needle]);
            printf("e-%d\n",num_of_zero);
        }
    }
	return 0;
}
