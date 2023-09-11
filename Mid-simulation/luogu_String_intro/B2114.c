#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
char toPair(char a){
    if(a=='A')return 'T';
    else if(a=='T')return 'A';
    else if(a=='C')return 'G';
    else if(a=='G')return 'C';
}
int main(){
    char s1[1000]="",s2[1000]="";
    scanf("%s",s1);
    int i,j=0;
    for(i=0;i<strlen(s1);i++){
        s2[j++]=toPair(s1[i]);
    }
    s2[j]='\0';
    puts(s2);
    return 0;
}