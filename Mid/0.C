#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

int main(){
    double ans=84.0-25-87*0.35;
    ans/= 0.40;
    printf("%f\n",ans);
    return 0;
}