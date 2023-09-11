#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
char key[100];
struct node{
    char element;
    struct node *next;
};

int isVisibleChar(char ch){
    int tmp=ch;
    if(32<=tmp&&tmp<=126)return 1;
    else return 0;
}

int main(){
    FILE *_in,*_out;
    /*   open files   */
    if((_in=fopen("in.txt","r"))==NULL){
        printf("can not find in.txt!\n");
        return 1;
    }
    if((_out=fopen("in_crpyt.txt","w"))==NULL){
        printf("can not find in_crpyt.txt!\n");
        return 2;
    }
    /*   create a linked list with length of 95   */
    struct node *head=NULL,*p=NULL,*q=NULL;
    for(int i=0;i<95;i++){
        q=(struct node*)malloc(sizeof(struct node));
        q->next=NULL;
        if(head==NULL){
            head=p=q;
        }
        else{
            p->next=q;
            p=p->next;
        }
    }
    p->next=head;
    /*   input key   */
    gets(key);
    /*   get the ring   */
    struct node *cur=head,*precur=p;
    int used[1000]={0};
    for(int i=0;key[i]!='\0';i++){
        if(used[key[i]]==0){
            cur->element=key[i];
            precur=cur,cur=cur->next;
            used[key[i]]=1;//mark the repeated char
        }
    }
    for(char x=32;x<=126;x++){
        if(used[x]==0){
            cur->element=x;
            precur=cur,cur=cur->next;
        }
    }
    /*   get char table   */
    char table[1000];//密码表
    int step;//步长
    int cnt=95;//链表长度
    char save=cur->element,src,dest;
    
    src=save;
    step=save;
    precur->next=cur->next;
    free(cur);
    cnt--;
    cur=precur->next;
    while(1){
        // boundary:
        if(cnt==1){
            table[cur->element]=save;
            break;
        }
        
        for(int i=1;i<=step;i++){
            dest=cur->element;
            if(i<step)precur=cur,cur=cur->next;
        }
        table[src]=dest;

        src=dest;
        step=src;

        precur->next=cur->next;
        free(cur);
        cnt--;
        cur=precur->next;
    }
    /*   rewrite text   */
    char ch;
    while((ch=fgetc(_in))!=EOF){
        ch=isVisibleChar(ch)?table[ch]:ch;
        fputc(ch,_out);
    }
    /*   close files   */
    fclose(_in);
    fclose(_out);
    return 0;
}