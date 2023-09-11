#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

int main(){
    char s1[]="ÄãºÃ";
    char s2[100]="";
    gets(s2);
    puts(s1);
    puts(s2);
    printf("¹þ¹þ¹þ\n");
    printf("%d\n",strlen(s1));
    return 0;
}