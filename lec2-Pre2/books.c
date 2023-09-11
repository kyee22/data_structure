#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
char title[1000][100],author[1000][100],press[1000][100],date[1000][100];
int cnt,op;
int main(){
    FILE *_in,*_out;
    if((_in=fopen("books.txt","r"))==NULL){
        printf("can not find books.txt!\n");
        return 1;
    }
    if((_out=fopen("ordered.txt","w"))==NULL){
        printf("can not find ordered.txt!\n");
        return 2;
    }
    while(fscanf(_in,"%s%s%s%s",title[cnt],author[cnt],press[cnt],date[cnt])!=EOF){
        cnt++;
        // printf("%d:%-50s%-20s%-30s%-10s\n",cnt,title[cnt-1],author[cnt-1],press[cnt-1],date[cnt-1]);
    }
    /*   bubble sort  */
    for(int i=1;i<cnt;i++){
        for(int j=0;j<cnt-i;j++){
            if(strcmp(title[j],title[j+1])>0){
                char tmp_title[100],tmp_author[100],tmp_press[100],tmp_date[100];
                //swap:
                strcpy(tmp_title,title[j]);//1
                strcpy(title[j],title[j+1]);
                strcpy(title[j+1],tmp_title);
                strcpy(tmp_author,author[j]);//2
                strcpy(author[j],author[j+1]);
                strcpy(author[j+1],tmp_author);
                strcpy(tmp_press,press[j]);//3
                strcpy(press[j],press[j+1]);
                strcpy(press[j+1],tmp_press);
                strcpy(tmp_date,date[j]);//4
                strcpy(date[j],date[j+1]);
                strcpy(date[j+1],tmp_date);
            }
        }
    }
    // for(int i=0;i<cnt;i++){
    //     printf("%-2d:%-50s%-20s%-30s%-10s\n",i+1,title[i],author[i],press[i],date[i]);
    // }
    char new_title[100],new_author[100],new_press[100],new_date[100],key[100];
    while(scanf("%d",&op)!=EOF){
        if(op==0){
            break;
        }
        else if(op==1){
            scanf("%s%s%s%s",new_title,new_author,new_press,new_date);
            if(strcmp(new_title,title[0])<0){
                for(int x=cnt-1;x>=0;x--){
                    strcpy(title[x+1],title[x]);
                    strcpy(author[x+1],author[x]);
                    strcpy(press[x+1],press[x]);
                    strcpy(date[x+1],date[x]);
                }
                strcpy(title[0],new_title);
                strcpy(author[0],new_author);
                strcpy(press[0],new_press);
                strcpy(date[0],new_date);
            }
            else if(strcmp(new_title,title[cnt-1])>0){
                strcpy(title[cnt],new_title);
                strcpy(author[cnt],new_author);
                strcpy(press[cnt],new_press);
                strcpy(date[cnt],new_date);
            }
            else{
                for(int needle=0;needle<cnt-1;needle++){
                    if(strcmp(new_title,title[needle])>0&&strcmp(new_title,title[needle+1])<0){
                        for(int x=cnt-1;x>=needle+1;x--){
                            strcpy(title[x+1],title[x]);
                            strcpy(author[x+1],author[x]);
                            strcpy(press[x+1],press[x]);
                            strcpy(date[x+1],date[x]);
                        }
                        strcpy(title[needle+1],new_title);
                        strcpy(author[needle+1],new_author);
                        strcpy(press[needle+1],new_press);
                        strcpy(date[needle+1],new_date);
                        break;
                    }
                }
            }
            cnt++;
            // for(int i=0;i<cnt;i++){
            //     printf("%-2d:%-50s%-20s%-30s%-10s\n",i+1,title[i],author[i],press[i],date[i]);
            // }
        }
        else if(op==2){
            scanf("%s",key);
            for(int i=0;i<cnt;i++){
                if(strstr(title[i],key)!=NULL){
                    printf("%-50s%-20s%-30s%-10s\n",title[i],author[i],press[i],date[i]);
                }
            }
        }
        else if(op==3){
            scanf("%s",key);
            for(int i=0;i<cnt;i++){
                if(strstr(title[i],key)!=NULL){
                    for(int x=i+1;x<cnt;x++){
                            strcpy(title[x-1],title[x]);
                            strcpy(author[x-1],author[x]);
                            strcpy(press[x-1],press[x]);
                            strcpy(date[x-1],date[x]);
                    }
                    cnt--;
                    i--;//attention:i位置上项发生变化,还要再次判断!
                }
            }
        }
    }
    for(int i=0;i<cnt;i++){
        fprintf(_out,"%-50s%-20s%-30s%-10s\n",title[i],author[i],press[i],date[i]);
    }
    fclose(_in);
    fclose(_out);
    return 0;
}
