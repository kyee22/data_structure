#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
char mom[100000]="A Stack is a container of objects that are inserted and removed according to the last-in first-out  principle.???";
void insert(int pos,char s[]){
    char hold[100000]={};
    strcpy(hold,mom);
    int len1=strlen(mom),len2=strlen(s),i=0,j=0;
    if(mom==NULL)return ;
    if(s==NULL)return ;
    if(pos>len1)return ;

    for(i=0,j=pos;i<len2;i++)mom[j++]=s[i];
    for(i=pos;i<len1;i++)mom[j++]=hold[i];
    mom[j]='\0';
}
char *delete(int pos,int len2){
    int i=0,j=pos;
    char *p=malloc(sizeof(char)*1000000);
    int len1=strlen(mom);
    if(pos>=len1)return NULL;
    for(;j<len1&&i<len2;j++){
        p[i++]=mom[j];
    }
    mom[pos]='\0';
    p[i]='\0';
    return p;
}

int main(){
    char s2[]="Objects",*ptr=NULL;
    ptr=delete(110,2);
    insert(110,s2);
    puts(mom);
    puts(ptr);

    return 0;
}
