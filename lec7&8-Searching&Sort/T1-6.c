#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

int main(){
    int a;
    scanf("%d",&a);
    while(~scanf("%d",&a))if(a%13==1)printf("%d\n",a);
    return 0;
}