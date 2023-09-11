#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
long long isprime(long long n){
    long long flag=0;
    for(long long i=2;i*i<=n;i++){
        if(n%i==0){
            flag=1;
        }
    }
    if(flag==1){
        return 0;//不是质数
    }
    else{
        return 1;//是质数
    }
}

int main(){
    FILE *out=fopen("Prime.txt","w");
    for(LL i=2;i<2807303+100;i++){
        if(isprime(i)){
            fprintf(out,"%lld\n",i);
        }
    }

    return 0;
}