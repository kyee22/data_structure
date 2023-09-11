#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

int main(){
    char s[10000]="",len1[10000]="",len2[10000]="",tmp[10000]="";
    int min=1000000,max=-1,cnt=0;
    gets(s);
    for(int i=0;s[i]!='\0';i++){
        if(!isalpha(s[i])){
            if(cnt){
                tmp[cnt++]='\0';
                int len=strlen(tmp);
                if(len>max){
                    strcpy(len1,tmp);
                    max=len;
                }
                if(len<min){
                    strcpy(len2,tmp);
                    min=len;
                }
            }
            cnt=0;
            tmp[cnt]='\0';
            continue;
        }
        tmp[cnt++]=s[i];
    }
    puts(len1);
    puts(len2);
    return 0;
}