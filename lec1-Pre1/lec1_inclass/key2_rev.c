#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
void rev(char s[]){
    int i=0,j=strlen(s)-1;
    for(;i<j;i++,j--){
        char tmp=s[i];
        s[i]=s[j];
        s[j]=tmp;
    }
}
int main(){
    char str[100];
    scanf("%s",str);
    rev(str);
    puts(str);
    return 0;
}