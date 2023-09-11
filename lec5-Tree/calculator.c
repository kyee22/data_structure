#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

typedef int DataType;
enum symType {DATA,OP};

struct item{
    enum symType ttype;
    
        DataType data;
        char op;
    
};
int pri[10000];
struct item suffexp[100000];
int cnt=0;
char s[100000];
char stack1[100000];int top1=-1; 


struct ETnode{
    struct item token;
    struct ETnode *left;
    struct ETnode *right;
};
struct ETnode *stack2[1000000];int top2=-1;

DataType compute(struct ETnode *p);
void insertET(struct item m);

int main(){
    pri['+']=1;pri['-']=1;pri['*']=2;pri['/']=2;pri['(']=3;pri[')']=3;

    /*  step 1: get suffix expression   */
    gets(s);
    int num=0;
    for(int i=0;s[i]!='\0';i++){
        if(isdigit(s[i])){
            num=num*10+s[i]-'0';

            if(!isdigit(s[i+1])){
                suffexp[cnt].ttype=DATA;
                suffexp[cnt++].data=num;
                num=0;
            }
        }
        else if(s[i]==')'){
            char tmp;
            while((tmp=stack1[top1--])!='('){
                suffexp[cnt].ttype=OP;
                suffexp[cnt++].op=tmp;
            }
        }
        else if(s[i]=='('){
            stack1[++top1]=s[i];
        }
        else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            if(top1==-1)
                stack1[++top1]=s[i];
            else if(stack1[top1]=='('){
                stack1[++top1]=s[i];
            }
            else if(pri[stack1[top1]]<pri[s[i]]){
                stack1[++top1]=s[i];
            }
            else{
                char tmp;
                while((top1>-1)&&(pri[stack1[top1]]>=pri[s[i]])&&((tmp=stack1[top1--])!='(')){
                    suffexp[cnt].ttype=OP;
                    suffexp[cnt++].op=tmp;
                }
                if(tmp=='('){
                    stack1[++top1]=tmp;
                }
                stack1[++top1]=s[i];
            }
        }
    }
    while(top1>-1){
        suffexp[cnt].ttype=OP;
        suffexp[cnt++].op=stack1[top1--];
    }
/* 
 *   evaluate step 1: 
*/
    // for(int i=0;i<cnt;i++){
    //     if(suffexp[i].ttype==DATA){
    //         printf("%d\n",suffexp[i].data);
    //     }
    //     else if(suffexp[i].ttype==OP){
    //         printf("%c\n",suffexp[i].op);
    //     }
    // }

    /*   step 2: create ET   */
    for(int i=0;i<cnt;i++){
        insertET(suffexp[i]);
    }
    /*   step 3: calculate and output   */
    struct ETnode *root=stack2[top2--];
    DataType result=compute(root);
    printf("%c ",root->token.op);
    if(root->left!=NULL){if(root->left->token.ttype==OP)printf("%c ",root->left->token.op);else printf("%d ",root->left->token.data);}
    if(root->right!=NULL){if(root->right->token.ttype==OP)printf("%c\n",root->right->token.op);else printf("%d\n",root->right->token.data);}
    printf("%d\n",result);
    return 0;
}

DataType compute(struct ETnode *p){
    DataType n1,n2,ans;
    if(p->token.ttype==OP){
        n1=compute(p->left);
        n2=compute(p->right);
        switch(p->token.op){
            case '+':ans=n1+n2;break;
            case '-':ans=n1-n2;break;
            case '*':ans=n1*n2;break;
            case '/':ans=n1/n2;break;
        }
        return ans;
    }
    else if(p->token.ttype==DATA){
        return p->token.data;
    }
}
void insertET(struct item m){
    struct ETnode *p=(struct ETnode*)malloc(sizeof(struct ETnode));
    p->token=m;
    p->left=NULL;
    p->right=NULL;
    if(m.ttype==DATA){
        stack2[++top2]=p;
    }
    else if(m.ttype==OP){
        p->right=stack2[top2--];
        p->left=stack2[top2--];
        stack2[++top2]=p;
    }
}