#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

int main(){
    double d_cm=(3.0/10.0)*334.6375/2;
    d_cm=((int)(d_cm*100.0))/100.0;
    printf("%f\n",d_cm);
    return 0;
}