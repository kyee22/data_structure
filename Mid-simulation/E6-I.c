#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

int main(){
    char ch;
    while(scanf("%c",&ch)!=EOF){
        if(ch=='\"'){
            do{
                putchar(ch);
                if(ch=='\"')break;
            }while(scanf("%c",&ch)!=EOF);
        }
        else if(ch=='\''){
            do{
                putchar(ch);
                if(ch=='\'')break;
            }while(scanf("%c",&ch)!=EOF);
        }
        else if(ch=='/'){
            ch=getchar();
            if(ch=='/'){
                while(scanf("%c",&ch)!=EOF){
                    if(ch=='\n')break;
                }
                putchar(ch);
            }
            else if(ch=='*'){
                while(scanf("%c",&ch)!=EOF){
                    if(ch=='*'){
                        ch=getchar();
                        if(ch=='/')break;
                        else ungetc(ch,stdin);
                    }
                }
            }
            else{
                putchar('/');
                putchar(ch);
            }
        }
        else{
            putchar(ch);
        }
    }
    return 0;
}