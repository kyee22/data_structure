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

struct word_fre{
    char word[10000];
    int time;
};

struct word_fre list[100000];

int main(){
    FILE *_in;
    if((_in=fopen("article.txt","r"))==NULL){
        printf("can not find article.txt!\n");
        return 1;
    }
    //input and stat
    while(fscanf(_in,"%c",&ch)!=EOF){
        if (('a'<=ch&&ch<='z')||('A'<=ch&&ch<='Z')){//case 1:是英文字母————则计入tmp_word
            tmp_word[cnt++]=tolower(ch);
        }
        else{
            if(!cnt){//case 2:tmp_word为空,当前字符又不是英文字母————跳过
                continue;
            }
            //case 3:形成1个单词————新单词则计入list,旧单词则统计time
            tmp_word[cnt]='\0';
            int is_new_word=1;//判断是否为新单词的标记
            for(int i=0;i<num_of_word;i++){
                if(strcmp(list[i].word,tmp_word)==0){
                    is_new_word=0;
                    list[i].time++;
                }
            }
            if(is_new_word){
                strcpy(list[num_of_word].word,tmp_word);
                list[num_of_word++].time=1;
            }
            cnt=0;
        }
    }
    //bubble sort
    for(int i=1;i<num_of_word;i++){
        for(int j=0;j<num_of_word-i;j++){
            if(strcmp(list[j].word,list[j+1].word)>0){
                //swap:
                struct word_fre tmp;
                tmp=list[j];
                list[j]=list[j+1];
                list[j+1]=tmp;
            }
        }
    }
    //output
    for(int i=0;i<num_of_word;i++){
        printf("%s %d\n",list[i].word,list[i].time);
    }
    fclose(_in);
    return 0;
}
