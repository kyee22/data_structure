#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

char toPair(char a){
    if(islower(a))return toupper(a);
    else if(isupper(a))return tolower(a);
}
char move(char a){
    if(isupper(a)){
        if (a<='W')return a+3;
        else return a-23;
    }
    else{
        if (a<='w')return a+3;
        else return a-23;
    }
}
void reverse(char s[]){
    int i=0,j=0;
    while(s[j])j++;
    for(j--;i<j;i++,j--){
        char tmp=s[i];
        s[i]=s[j];
        s[j]=tmp;
    }
}
int main(){
    char s1[1000]="",s2[1000]="";
    gets(s1);
    int i=0,j=0;
    for(;i<strlen(s1);i++){
        s2[j++]=toPair(move(s1[i]));
    }
    s2[j]='\0';
    reverse(s2);
    puts(s2);
    return 0;
}