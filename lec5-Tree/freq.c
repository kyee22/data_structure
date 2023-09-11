#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
char tmp_word[10000],ch;
int cnt,num_of_word;

struct tnode{
    char word[10000];
    int cont;
    struct tnode *left;
    struct tnode *right;
};
struct tnode *addTree(struct tnode *p,char *s){
    int cond;
    if(p==NULL){
        p=(struct tnode*)malloc(sizeof(struct tnode));
        strcpy(p->word,s);
        p->cont=1;
        p->left=NULL;
        p->right=NULL;
    }
    else if((cond=strcmp(s,p->word))==0){
        p->cont++;
    }
    else if(cond<0){
        p->left=addTree(p->left,s);
    }
    else if(cond>0){
        p->right=addTree(p->right,s);
    }

    return p;
}

void printTree(struct tnode *p){
    if(p!=NULL){
        printTree(p->left);
        printf("%s %d\n",p->word,p->cont);
        printTree(p->right);
    }
}
int main(){
    FILE *in;
    in=fopen("article.txt","r");
    struct tnode* root=NULL;
    
    //input and stat
    while((ch=fgetc(in))!=EOF){
        if (isalpha(ch)){//case 1:是英文字母————则计入tmp_word
            tmp_word[cnt++]=tolower(ch);
        }
        else{
            if(!cnt){//case 2:tmp_word为空,当前字符又不是英文字母————跳过
                continue;
            }
            //case 3:形成1个单词————新单词则计入list,旧单词则统计time
            tmp_word[cnt]='\0';
            root=addTree(root,tmp_word);
            cnt=0;
        }
    }
    // printf("********\n%d\n",root==NULL);
    if(root->right->right!=NULL)printf("%s %s %s\n",root->word,root->right->word,root->right->right->word);
    else if(root->right!=NULL)printf("%s %s\n",root->word,root->right->word);
    else if(root!=NULL)printf("%s\n",root->word);
    printTree(root);

    fclose(in);
    return 0;
}
