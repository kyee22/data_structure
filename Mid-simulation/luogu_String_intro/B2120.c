#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
char s[10000];
int main(){
    int cnt=0;
    gets(s);
    for(int i=0;s[i]!='\0';i++){
        if(s[i]==' '){
            if(cnt)printf("%d,",cnt);
            cnt=0;
            continue;
        }
        else{
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}