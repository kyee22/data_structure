#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
#define maxsize 100000
char line[maxsize],s[maxsize];
struct Ops{
    int Op;
    int Pos;
    char str[10000];
};
struct Ops rec[maxsize];
int top=-1,n;

void insert(int pos,char s[]){
    char hold[maxsize]={};
    strcpy(hold,line);
    int len1=strlen(line),len2=strlen(s),i=0,j=0;
    if(line==NULL)return ;
    if(s==NULL)return ;
    if(pos>len1)return ;

    for(i=0,j=pos;i<len2;i++)line[j++]=s[i];
    for(i=pos;i<len1;i++)line[j++]=hold[i];
    line[j]='\0';
}

char *delete(int pos,int len2){
    int i=0,j=pos,x=pos;
    char *p=malloc(sizeof(char)*maxsize);
    int len1=strlen(line);
    if(pos>=len1)return NULL;
    for(;j<len1&&i<len2;j++){
        p[i++]=line[j];
    }
    for(;j<len1;j++){
        line[x++]=line[j];
    }
    line[x]='\0';
    p[i]='\0';
    return p;
}

int main(){
    fgets(line,maxsize-1,stdin);
    scanf("%d",&n);
    while(n--){
        top++;
        scanf("%d%d%s",&rec[top].Op,&rec[top].Pos,rec[top].str);
    }
    int op,pos,len2;
    while(~scanf("%d",&op)){
        if(op==-1)break;
        else if(op==1){
            scanf("%d%s",&pos,s);

            insert(pos,s);

            top++;
            rec[top].Op=op,rec[top].Pos=pos,strcpy(rec[top].str,s);
        }
        else if(op==2){
            scanf("%d%d",&pos,&len2);

            char *ptr=delete(pos,len2);

            top++;
            rec[top].Op=op,rec[top].Pos=pos,strcpy(rec[top].str,ptr);
        }
        else if(op==3){
            if(top<=-1){
                continue;
            }
            
            if(rec[top].Op==1){
                delete(rec[top].Pos,strlen(rec[top].str));
            }
            else if(rec[top].Op==2){
                insert(rec[top].Pos,rec[top].str);
            }
            top--;
        }
    }
    puts(line);
    return 0;
}
