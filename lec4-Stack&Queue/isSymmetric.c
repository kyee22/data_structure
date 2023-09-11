#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
int isSymmetric(char s[]){
    int i=0,j=0;
    while(s[j])j++;
    for(j--;i<j&&s[i]==s[j];i++,j--);
    return (i>=j);
}
int main(){
    char a[]="abccba";//偶数长度对称
    char b[]="abcba";//奇数长度对称
    char c[]="a";
    char d[]="aa";
    char e[]="abcabc";
    printf("%d\n",isSymmetric(a));
    printf("%d\n",isSymmetric(b));
    printf("%d\n",isSymmetric(c));
    printf("%d\n",isSymmetric(d));
    printf("%d\n",isSymmetric(e));
    return 0;
}