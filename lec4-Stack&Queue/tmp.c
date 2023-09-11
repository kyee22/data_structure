#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long 

int main(){
    int a[]={1,2,3,4},*p=&a[2];
    printf("%d ",++*p);
    printf("%d\n",*p);
    printf("%d\n",*--p);
    return 0;
}