#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

struct st{
    int x;
    int *y;
}*p;

int main(){
    int a[]={1,2},b[]={3,4};
    struct st c[2]={100,a,20,b};
    p=c;
    // printf("(A) *p->y = %d\n",*p->y);
    // printf("(B) p->x = %d\n",p->x);
    printf("(C) ++p->x = %d\n",++p->x);
    printf("(D) (p++)->x = %d\n",(p++)->x);
    printf("%d\n",p->x);
    return 0;
}