#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

int main(){
    int i=32;
    for(;i<=126;i++)
        printf(i%5!=0?"%3d: %c   ":"%3d: %c\n",i,i);

    return 0;
}