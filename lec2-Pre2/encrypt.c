#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
char password[100];

int main(){
    FILE *_in,*_out;
    if((_in=fopen("encrypt.txt","r"))==NULL){
        printf("can not find encrypt.txt!\n");
        return 1;
    }
    if((_out=fopen("output.txt","w"))==NULL){
        printf("can not find output.txt!\n");
        return 2;
    }
    /*   get alpha table   */
    int used[1000]={0},cnt=0,i=0;
    char table[1000];
    gets(password);
    for(;password[i]!='\0';i++){
        if(used[password[i]]==0){
            table[cnt++]=password[i];
            used[password[i]]=1;
        }
    }
    for(char x='z';x>='a';x--){
        if(used[x]==0){
            table[cnt++]=x;
        }
    }
    table[cnt]='\0';
    
    /*   read   */
    char ch;
    while((ch=fgetc(_in))!=EOF){
        if('a'<=ch&&ch<='z'){
            ch=table[ch-'a'];
        }
        fputc(ch,_out);
    }

    fclose(_in);
    fclose(_out);
    return 0;
}