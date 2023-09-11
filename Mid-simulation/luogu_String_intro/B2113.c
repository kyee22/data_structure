#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

int main(){
    char old[200]="",new[200]="";
    scanf("%s",old);
    int len=strlen(old),i;
    for(i=0;i<len;i++){
        new[i]=old[i%len]+old[(i+1)%len];
    }
    new[i]='\0';
    puts(new);
    return 0;
}