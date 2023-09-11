#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
char s[100000];
int main(){
    int i=0,j=0;
    scanf("%s",s);
    while(s[j])j++;
    for(j--;i<j;i++,j--){
        if(s[i]!=s[j]){
            printf("no\n");
            return 0;
        }
    }
    printf("yes\n");
    return 0;
}