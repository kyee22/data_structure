#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

struct log_item{
    int stuID;
    char stuName[50];
    int maID;
    char logTime[50];
}stuList[1000],ansList[500];

int Num,
    cnt;

int isIn_stuList(int stuID){//寻找是否已经录入到stuList:找到,返回第一次录入时的机器号;否则,返回--1
    for(int i=0;i<Num;i++){
        if(stuID==stuList[i].stuID){//找到
            return stuList[i].maID;
        }
    }
    return -1;//未找到
}

int isIn_ansList(int stuID){//寻找是否已经录入到ansList:找到,返回1;否则,返回0
    for(int i=0;i<cnt;i++){
        if(stuID==ansList[i].stuID){//找到
            return 1;
        }
    }
    return 0;//未找到
}
int cmp(const void *p,const void *q){
    struct log_item *a=(struct log_item *)p;
    struct log_item *b=(struct log_item *)q;
    return a->stuID-b->stuID;
}
int main(){
    int num_log,stuID,maID;
    char stuName[50],logTime[50];
    scanf("%d",&num_log);
    for(int i=0;i<num_log;i++){
        scanf("%d%s%d%s",&stuID,stuName,&maID,logTime);
        int cond=isIn_stuList(stuID);

        if(cond==-1){//case 1:未找到,录入stuList
            stuList[Num].stuID=stuID;
            stuList[Num].maID=maID;
            strcpy(stuList[Num].stuName,stuName);
            strcpy(stuList[Num].logTime,logTime);

            Num++;
        }
        else{//case 2:找到
            if(cond==maID){//2.1:同一设备登陆,不作处理
                ;
            }
            else{//2.2:不同设备登陆,列入ansList

                if(isIn_ansList(stuID)==0){
                    ansList[cnt].stuID=stuID;
                    ansList[cnt].maID=maID;
                    strcpy(ansList[cnt].stuName,stuName);
                    strcpy(ansList[cnt].logTime,logTime);

                    cnt++;
                }
            }
        }
    }
    qsort(ansList,cnt,sizeof(struct log_item),cmp);
    for(int i=0;i<cnt;i++)printf("%d %s\n",ansList[i].stuID,ansList[i].stuName);
    return 0;
}