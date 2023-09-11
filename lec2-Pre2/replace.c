#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
char line[100000],key_1[100000],key_2[100000];
int main(){
    FILE *_in,*_out;
    if((_in=fopen("filein.txt","r"))==NULL){
        printf("can not find filein.txt!\n");
        return 1;
    }
    if((_out=fopen("fileout.txt","w"))==NULL){
        printf("can not find fileout.txt!\n");
        return 2;
    }
    scanf("%s%s",key_1,key_2);
    while((fgets(line,100000-1,_in))!=NULL){
        printf("line:%s",line);
        char save[100000]={};
        int i,cnt=0;
        for(i=0;line[i]!='\0';i++){
            if(tolower(line[i])!=tolower(key_1[0])){
                save[cnt++]=line[i];//没找到
            }
            else{
                int j=i,k=0;
                for(;key_1[k]!='\0';j++,k++){
                    if(tolower(key_1[k])!=tolower(line[j]))break;
                }
                if(key_1[k]=='\0'){
                    for(int x=0;key_2[x]!='\0';x++){
                        save[cnt++]=key_2[x];
                    }
                    i+=strlen(key_1)-1;
                }
                else{
                    save[cnt++]=line[i];//没找到
                }
            }
        }
        save[cnt++]='\0';
        printf("save:%s",save);
        fputs(save,_out);
    }
    fclose(_in);
    fclose(_out);
    return 0;
}