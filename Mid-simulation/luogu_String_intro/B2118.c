#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

int main(){
    char s1[1000]="",s2[1000]="";
    scanf("%s%s",s1,s2);
    if(strlen(s1)<=strlen(s2)){
        if(strstr(s2,s1)!=NULL){
            printf("%s is substring of %s\n",s1,s2);
            return 0;
        }
    }
    else{
        if(strstr(s1,s2)!=NULL){
            printf("%s is substring of %s\n",s2,s1);
            return 0;
        }   
    }
    printf("No substring\n");
    return 0;
}