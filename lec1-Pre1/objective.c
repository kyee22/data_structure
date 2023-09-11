#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long


int main()
{
    char str[]="\t\v\\\0will\n";
    char s[]="will_you_become_a_hero?\n";
    printf("%d",strlen(str));
    return 0;
}
