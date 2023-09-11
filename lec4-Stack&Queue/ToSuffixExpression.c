#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
#define DataType double
#define maxsize 10000
DataType stack[maxsize];
int top=-1;
int isEmpty(){
    return top==-1;
}
int isFull(){
    return top==maxsize;
}
void push(DataType ch){
    stack[++top]=ch;
}
DataType pop(){
    return stack[top--];
}

char *getExp(char s[]);
DataType compute(DataType a,DataType b,char op);


int main(){
    char s[maxsize];
    fgets(s,maxsize-1,stdin);
    char *exp=getExp(s);
    DataType num=0,n1,n2;int flag=0,len=strlen(exp);
    puts(exp);
    // for (int i = 0; i < len ; i++) {
    //     if (isdigit(exp[i])) {
    //         num = 10 * num + exp[i] - '0';
    //         flag = 1;
    //     } 
    //     else {
    //         if (flag) {//如果为1，说明有数字读入
    //             push(num);
    //             num = 0;
    //             flag = 0;
    //         }
    //         if(isspace(exp[i]))continue;
    //         else if(exp[i] != '.') {//数字间隔符，不是间隔符就是运算符
    //             n2 = pop();
    //             n1 = pop();
    //             push(compute(n1,n2,exp[i]));
    //         }
    //     }
    // }
    // printf("%.2f\n",pop());
    return 0;
}

char *getExp(char s[]){
    char *tmpStack=(char *)malloc(sizeof(char)*maxsize);
    int top=-1;
    char *exp=(char *)malloc(sizeof(char)*maxsize);
    int e=0;
    for(int i=0;s[i]!='\0';i++){
        while(isdigit(s[i])||isalpha(s[i])||s[i]=='.'){
            exp[e++]=s[i++];
        }
        exp[e++]=' ';

        if(isspace(s[i]))
            continue;
        else {
            if(s[i]=='+'||s[i]=='-'){
                if(top==-1)
                    tmpStack[++top]=s[i];
                else{
                    char tmp;
                    while((top>-1)&&((tmp=tmpStack[top--])!='(')){
                        exp[e++]=tmp;
                    }
                    if(tmp=='('){
                        tmpStack[++top]=tmp;
                    }
                    tmpStack[++top]=s[i];
                }
            }
            else if(s[i]==')'){
                char tmp;
                while((tmp=tmpStack[top--])!='('){
                    exp[e++]=tmp;
                }
            }
            else if(s[i]=='('||s[i]=='*'||s[i]=='/'){
                tmpStack[++top]=s[i];
            }
        }
    }
    while(top>-1){
        exp[e++]=tmpStack[top--];
    }
    exp[e]='\0';
    return exp;
}
DataType compute(DataType a,DataType b,char op){
    switch(op){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
    }
}