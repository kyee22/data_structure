#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
char name[1000][50],tel[1000][50],_name[1000][50],_tel[1000][50];
int cnt,_cnt,judged[1000];
int main(){
    /*   input   */
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++){
        scanf("%s%s",name[i],tel[i]);
    }
    /*   修正旧列表，得到新列表   */
    for(int i=0;i<cnt;i++){
        if(judged[i]==1)
            continue;
        /*   旧列表中应该存入新列表的项有两类   */
        //第1类:没有被judge，说明是独一无二的项，应该存入新列表
        strcpy(_name[_cnt],name[i]);
        strcpy(_tel[_cnt],tel[i]);
        _cnt++;

        int repeat_time=0;
        for(int j=i+1;j<cnt;j++){
            if(judged[j]==1)
                continue;
            if(strcmp(name[i],name[j])==0){
                judged[j]=1;//name重复,需要judge,标记judged[j]=1
                if(strcmp(tel[i],tel[j])==0){
                    ;
                }
                else{
                    //第2类:name重复但tel不重复的项，应该存入新列表
                    char tmp[3]="";
                    repeat_time++;
                    tmp[0]='_';
                    tmp[1]='0'+repeat_time-0;
                    tmp[2]='\0';
                    strcpy(_name[_cnt],name[i]);
                    strcat(_name[_cnt],tmp);
                    strcpy(_tel[_cnt],tel[j]);
                    _cnt++;
                    
                }
            }
            else{
                ;
            }
        }
    }

    /*   bubble sort   */
    int i,j;
    for(i=1;i<_cnt;i++){
        for(j=0;j<_cnt-i;j++){
            if(strcmp(_name[j],_name[j+1])>0){
                //swap:
                char tmp_name[1000]="",tmp_tel[1000]="";
                strcpy(tmp_name,_name[j]);
                strcpy(_name[j],_name[j+1]);
                strcpy(_name[j+1],tmp_name);
                strcpy(tmp_tel,_tel[j]);
                strcpy(_tel[j],_tel[j+1]);
                strcpy(_tel[j+1],tmp_tel);
            }
        }
    }
    /*   output   */
    for(int i=0;i<_cnt;i++){
        printf("%s",_name[i]);
        printf(" ");
        printf("%s",_tel[i]);
        printf("\n");
    }
    return 0;
}