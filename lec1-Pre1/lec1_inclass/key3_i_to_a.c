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
char i_to_a(int n,char s[]){
    int i=0,sign;
    if((sign=n)<0){
        n*=-1;
    }
    do{
        s[i++]=n%10+'0';
    }while((n/=10)>0);

    if(sign<0){
        s[i++]='-';
    }
    s[i]='\0';
    rev(s);
} 
int main(){
    int number;
    char str[100];
    scanf("%d",&number);
    i_to_a(number,str);
    puts(str);

    return 0;
}