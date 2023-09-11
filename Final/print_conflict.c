#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

int main(){
    int list[]={19,16,23,1,68,20,84,27,55,11,10,81},mOD=13;
    int len=sizeof(list)/sizeof(int);
    for(int i=0;i<len;i++){
        printf("%3d   mod  %3d   =  %3d\n",list[i],mOD,list[i]%mOD);
    }
    return 0;
}