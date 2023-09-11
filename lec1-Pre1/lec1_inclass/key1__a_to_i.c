#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
int a_to_i(char s[]){
    int tmp=0;
    for(int i=0;'0'<=s[i]&&s[i]<='9';i++){
        tmp=tmp*10+s[i]-'0';
    }
    return tmp;
}
int main(){
    int result;
    char str[100];
    scanf("%s",str);
    result=a_to_i(str);
    printf("%d\n",result);
    return 0;
}