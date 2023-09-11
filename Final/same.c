#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

struct node1{
    char tel[50];
    char station;
    char on_time[50];
    char off_time[50];
}list[2000];

struct node2{
    char tel[50];
    char station;
}ans[2000];
int num;
int cnt;

int cmp(const void *p,const void *q){
    struct node2 *a=(struct node2 *)p;
    struct node2 *b=(struct node2 *)q;
    if(strcmp(a->tel,b->tel)!=0)return strcmp(b->tel,a->tel);
    else return a->station-b->station;
}
int isinans(char tel[],char station){
    for(int i=0;i<cnt;i++){
        if(ans[i].station==station&&strcmp(ans[i].tel,tel)==0){
            return 1;
        }
    }
    return 0;
}
int main(){

    char tel[50],station,on_time[50],off_time[50];
    char target[50],target_station,target_on_time[50],target_off_time[50];

    scanf("%d\n",&num);
    for(int i=0;i<num;i++){
        scanf("%s %c%s%s",list[i].tel,&list[i].station,list[i].on_time,list[i].off_time);
        // 
    }
    scanf("%s",target);

    for(int i=0;i<num;i++){
        if(strcmp(list[i].tel,target)==0){
            // printf("->%s %c %s %s\n",list[i].tel,list[i].station,list[i].on_time,list[i].off_time);

            target_station=list[i].station;
            strcpy(target_on_time,list[i].on_time);
            strcpy(target_off_time,list[i].off_time);

            for(int j=0;j<num;j++){
                if((strcmp(list[j].tel,target)!=0)&&(list[j].station==target_station)&&!((strcmp(target_on_time,list[j].off_time)>0)||(strcmp(list[j].on_time,target_off_time)>0))){
                    
                    if(!isinans(list[j].tel,list[j].station)){
                        // printf("    ->%s %c %s %s\n",list[j].tel,list[j].station,list[j].on_time,list[j].off_time);
                        ans[cnt].station=list[j].station;
                        strcpy(ans[cnt].tel,list[j].tel);
                        cnt++;
                    }
                }
            }
        }
    }
    qsort(ans,cnt,sizeof(struct node2),cmp);
    for(int i=0;i<cnt;i++){
        printf("%s %c\n",ans[i].tel,ans[i].station);
    }
    return 0;
}