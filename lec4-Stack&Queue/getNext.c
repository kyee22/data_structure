#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
void getnext(char T[], int next[])
{  	
    int i=0, j=-1;
    next[0] = -1;
    while(T[i]!='\0'){
		if(j==-1 || T[i]==T[j]){ //i为后缀位置；j为前缀位置
        i++; 
        j++; 
        next[i]=j; 
      }
      else 
        j = next[j]; //若字符不同，则j值回溯
	 }  
}


int main(){
    char T[]="abxabmabxabxyzz";
    int *next = (int *)malloc(sizeof(int)*(strlen(T)+1));
    getnext(T,next);
    for(int j=0;T[j]!='\0';j++)printf("j: %2d  T[j]:%c  next[j]:%d\n",j,T[j],next[j]);
    return 0;
}