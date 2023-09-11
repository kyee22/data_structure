#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

int main(){
    char c;
    int cnt=0;
    while((c=getchar())!=EOF){
        if(isdigit(c))cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}