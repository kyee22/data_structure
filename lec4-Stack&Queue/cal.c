#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
#define maxsize 1000000

typedef double DataType;

enum symbol{Num,Op,Eq,Other};
enum oper{ept,add,min,mul,Div,left,right};
int pri[]={-1,0,0,1,1,2,2};
union sym
{
    DataType num;
    enum oper op;
};

DataType Num_stack[maxsize];
int Ntop=-1,Otop=-1;
enum oper Op_stack[maxsize];

enum symbol getSym(union sym *item);
void operate(enum oper op);
void compute(enum oper op);
void pushNum(DataType num);
DataType popNum();
void pushOp(enum oper op);
enum oper popOp();
enum oper topOp();

int main(){
    union sym item;
    enum symbol s;
    while((s=getSym(&item))!=Eq){
        if(s==Num){
            pushNum(item.num);
        }
        else if(s==Op){
            operate(item.op);
        }
    }
    while(Otop>=0){
        compute(popOp());
    }

    printf("%.2f\n",popNum());
    
    return 0;
}
enum symbol getSym(union sym *item){
    int ch,tmp;
    while((ch=getchar())!='='){
        if(isdigit(ch)){
            for(tmp=0;isdigit(ch);ch=getchar())
                tmp=10*tmp+ch-'0';
            ungetc(ch,stdin);
            item->num=(tmp*1.0);
            // printf("%f\n",item->num);
            return Num;
        }
        else{
            switch (ch)
            {
            case '+':item->op=add;return Op;
            case '-':item->op=min;return Op;
            case '*':item->op=mul;return Op;
            case '/':item->op=Div;return Op;
            case '(':item->op=left;return Op;
            case ')':item->op=right;return Op;
            case ' ':
            case '\t':
            case '\n':
                break;
            default:
                return Other;
            }
        }
    }
    return Eq;
}
void pushNum(DataType num){
    if(Ntop == maxsize -1){
        printf("Data stack is full!");
        return ;
    }
    Num_stack[++Ntop]= num;
}
DataType popNum(){
    if(Ntop==-1){
        printf("Error in the expression!8888\n");
        return 2;
    }
    return Num_stack[Ntop--];
}
void pushOp(enum oper op){
    if(Otop==maxsize-1){
        printf("Data stack is full!");
        return ;
    }
    Op_stack[++Otop]=op;
}
enum oper popOp(){
    if(Otop!=-1){
        return Op_stack[Otop--];
    }
    return ept;
}
enum oper topOp(){
    return Op_stack[Otop];
}
void operate(enum oper op){
    enum oper t;
    if(op!=right){
        while(pri[op]<=pri[topOp()]&&topOp()!=left){
            compute(popOp());
        }
        pushOp(op);
    }
    else{
        while((t=popOp())!=left)
            compute(t);
    }
}
void compute(enum oper op){
    DataType tmp;
    switch(op){
        case add:pushNum(popNum()+popNum());break;
        case min:
            tmp=popNum();
            pushNum(popNum()-tmp);break;
        case mul:
            pushNum(popNum()*popNum());break;
        case Div:
            tmp=popNum();
            pushNum(popNum()/tmp);break;
    }
}
