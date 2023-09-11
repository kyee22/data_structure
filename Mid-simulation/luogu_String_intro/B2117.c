#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

int main(){
    int num;
    char s[1000];
    scanf("%d",&num);
    while(num--){
        scanf("%s",s);
        for(int i=0;s[i]!='\0';i++){
            if(!isalpha(s[i])){
                continue;
            }

            s[i]=i==0?toupper(s[i]):tolower(s[i]);
        }
        puts(s);
    }
    return 0;
}