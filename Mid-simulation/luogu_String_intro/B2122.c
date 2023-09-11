#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
void reverse(char s[]){
    int i=0,j=0;
    while(s[j])j++;
    for(j--;i<j;i++,j--){
        char tmp=s[i];
        s[i]=s[j];
        s[j]=tmp;
    }
}
char s[10000]="";
int main(){
    while(scanf("%s",s)!=EOF){
        reverse(s);
        puts(s);
    }
    return 0;
}