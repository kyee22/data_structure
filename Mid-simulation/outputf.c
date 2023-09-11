#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
char f[1000000],s[1000000];
int len,m,n;

void printX(int n){
    for(int x=0;x<n;x++)printf("#");
}
int main(){
    char ch;
    int isRight=0;
    gets(f);
    gets(s);
    if(sscanf(f,"%%-%d:%dS",&m,&n)){
        isRight=1;
    }
    else{
        sscanf(f,"%%%d:%dS",&m,&n);
    }

    len=strlen(s);

    if(n<=len){
        for(int x=0;x<m&&s[x]!='\0';x++)printf("%c",s[x]);
        printf("\n");
    }
    else{
        if(isRight==1){
            printX(n-min(len,m));
            for(int x=0;x<m&&s[x]!='\0';x++)printf("%c",s[x]);
            printf("\n");
        }
        else{
            for(int x=0;x<m&&s[x]!='\0';x++)printf("%c",s[x]);
            printX(n-min(len,m));
            printf("\n");
        }
    }
    return 0;
}