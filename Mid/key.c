#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

char word[10000];
int used[100000];
char rec[10000];
int cnt,x;
void reverse(char s[]){
    int i=0,j=0;
    while(s[j])j++;
    for(j--;i<j;i++,j--){
        char tmp=s[i];
        s[i]=s[j];
        s[j]=tmp;
    }
}
int main(){
    // char ch;
    // while(scanf(" %c",&ch)!=EOF){
    //     if(isalpha(ch)){
    //         word[x++]=ch;
    //     }
    // }
    // word[x]='\0';
    fgets(word,10000,stdin);
    for(int i=0;word[i]!='\0';i++){
        if(isalpha(word[i])&&used[tolower(word[i])]==0){
            if(isupper(word[i]))word[i]=tolower(word[i]);
            rec[cnt++]=word[i];
            used[word[i]]=1;
        }
    }
    rec[cnt]='\0';
    // puts(rec);
    reverse(rec);
    // puts(rec);
    for(char i='z';i>='a';i--){
        if(!used[i]){
            rec[cnt++]=i;
        }
    }
    rec[cnt]='\0';
    // puts(rec);
    for(char i='a';i<='z';i++){
        int index=i-'a'+0;
        printf("%c %c\n",i,rec[index]);
    }
    
    return 0;
}