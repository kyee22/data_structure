#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
char s[100000];

int main(){
    gets(s);
    char lst=s[0];
    int cnt=1;
    for(int i=1;s[i]!='\0';i++){
        if(s[i]!=lst){
            printf("%d%c",cnt,lst);
            lst=s[i];
            cnt=1;
        }
        else{
            cnt++;
        }
    }
    printf("%d%c",cnt,lst);
    return 0;
}