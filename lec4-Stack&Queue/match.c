#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
int cnt,top=-1,idx=1,isMatched=1,ans_line,line[1000000],stack_line[1000000];
char record[1000000],stack[1000000],ch,ans_char;
//record记录依次所有的有效括号,最后从record往stack里压栈

int main(){
    /*   打开文件   */
    FILE *in;
    if((in=fopen("example.c","r"))==NULL){
        printf("can not find example.c!\n");
        return 1;
    }
    /*   input: record依次记录所有有效括号   */
    while((ch=fgetc(in))!=EOF){
        if(ch=='\n'){//①换行符
            idx++;
        }
        else if(ch=='\''){//②字符常量
            while((ch=fgetc(in))!=EOF){
                if(ch=='\n'){idx++;}
                if(ch=='\'')break;
            }
        }
        else if(ch=='\"'){//③字符串常量
            while((ch=fgetc(in))!=EOF){
                if(ch=='\n'){idx++;}
                if(ch=='\"')break;
            }
        }
        else if(ch=='/'){
            ch=fgetc(in);
            //④单行注释
            if(ch=='/'){
                while((ch=fgetc(in))!=EOF){
                    if(ch=='\n'){idx++;break;}
                }    
            }
            //⑤多行注释
            else if(ch=='*'){
                while((ch=fgetc(in))!=EOF){
                    if(ch=='\n'){idx++;}
                    if(ch=='*'){
                        ch=fgetc(in);
                        if(ch=='/')break;
                        else ungetc(ch,in);
                    }
                } 
            }
            //⑥其它情况，退回输入流
            else{ungetc(ch,in);}
        }
        else if(ch=='('||ch==')'||ch=='{'||ch=='}'){
            record[cnt]=ch;
            line[cnt++]=idx;
        }
        else{continue;}
    }
    /*   process: 从record往stack压栈   */
     for(int i=0;i<cnt;i++){
        if(top==-1){//栈为空
            if(record[i]=='{'||record[i]=='('){//匹配成功
                top++;
                stack[top]=record[i];
                stack_line[top]=line[i];
            }
            else{//匹配失败
                isMatched=0;
                ans_char=record[i];
                ans_line=line[i];
                printf("without maching \'%c\' at line %d\n",ans_char,ans_line);
                return 0;
            }
            continue;
        }
        //  栈不为空,那么栈里面一定只会是左括号,不会有右括号
        //  (因为右括号入栈的时候要么匹配失败则return 0,要么匹配成功则出栈)
        if(record[i]=='('){//直接入栈
            top++;
            stack[top]=record[i];
            stack_line[top]=line[i];
        }
        else if(record[i]=='{'){
            if(stack[top]=='('){//匹配失败
                isMatched=0;
                ans_char=stack[top];
                ans_line=stack_line[top];
                printf("without maching \'%c\' at line %d\n",ans_char,ans_line);
                return 0;
            }
            else{//入栈
                top++;
                stack[top]=record[i];
                stack_line[top]=line[i];
            }
        }
        else if(record[i]==')'){
            if(stack[top]=='('){//匹配成功
                top--;
            }
            else{//匹配失败
                isMatched=0;
                ans_char=record[i];
                ans_line=line[i];
                printf("without maching \'%c\' at line %d\n",ans_char,ans_line);
                return 0;
            }               
        }
        else if(record[i]=='}'){
            if(stack[top]=='{'){//匹配成功
                top--;
            }
            else{//匹配失败
                isMatched=0;
                ans_char=record[i];
                ans_line=line[i];
                printf("without maching \'%c\' at line %d\n",ans_char,ans_line);
                return 0;
            }               
        }

     }
     //栈里面还有未匹配的左括号
    if(top>=0){
        isMatched=0;
        ans_char=stack[top];
        ans_line=stack_line[top];
        printf("without maching \'%c\' at line %d\n",ans_char,ans_line);
        return 0;
    }
    //整个程序括号匹配
    if(isMatched){
        for(int i=0;i<cnt;i++)printf("%c",record[i]);
        printf("\n");
    }
    fclose(in);
    return 0;
}