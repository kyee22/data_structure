#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

int main(){
    char s[100];
    scanf("%s",s);
    int len=0;
    while(s[len])len++;
    if(s[len-1]=='y'&&s[len-2]=='l'){
        s[len-2]='\0';
    }
    else if(s[len-1]=='r'&&s[len-2]=='e'){
        s[len-2]='\0';
    }
    else if(s[len-1]=='g'&&s[len-2]=='n'&&s[len-3]=='i'){
        s[len-3]='\0';
    }
    puts(s);
    return 0;
}