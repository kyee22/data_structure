#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
#define maxsize 1000000
#define threshold 7
#define win_num_min 3
#define win_num_max 5
struct cust{
    int idx;
    int wait_time;
    int type;//determine the service_time of window
};
struct window{/*  isOpen和isOccupied相互独立, why? Just feel it...  */
    int isOpen;//isOpen随【人数】变化而主动调整
    int isOccupied;//isOccupied和service_time随【时间】流逝而自然变化
    int service_time;
};
struct cust queue[maxsize];
struct window winline[win_num_max+1];
int new[10000],font=1,rear=0/* 一般font=0,rear=maxsize-1,本题较特殊从1开始编号 */,cust_num=0,win_num=win_num_min;

int isEmpty();
int isFull();
void enQueue(int type);
struct cust deQueue();
int service();

int main(){
    int simulationtime,clock,type;
    for(int i=1;i<=5;i++){//initialize the 5 windows
        winline[i].isOccupied=0;
        winline[i].isOpen=(i<=3)?1:0;
        winline[i].service_time=0;
    }
    scanf("%d",&simulationtime);
    for(int i=1;i<=simulationtime;i++){//read the num of arrived at each clock
        scanf("%d",&new[i]);
    }
    for(clock=1;/*  即使"下班", 也要将队列中的所有人服务完之后才结束  */;clock++){
        //step1: 1个周期开始了, 若还未"下班", 则将客户入列
        if(clock<=simulationtime){
            for(int i=1;i<=new[clock];i++){
                scanf("%d",&type);
                enQueue(type);
            }
            //cust优先:尽量增加窗口
            while((cust_num/win_num)>=7&&win_num<win_num_max){
                win_num++;
                winline[win_num].isOpen=1;
            }
        }
        //step2: 提供服务
        if(service()==0&&clock>simulationtime){
            break;
        }
        //step3: 1个周期结束了, 增加队列所有成员的wait_time
        for(int i=font;i<=rear;i++){
            queue[i].wait_time++;
        }
    }

    return 0;
}


int isEmpty(){
    return cust_num==0;
}
int isFull(){
    return cust_num==maxsize;
}
void enQueue(int type){
    if(isFull()){
        printf("HAHAHAHAHHHHHH\n");
    }
    else{
        rear=(rear+1)%maxsize;
        queue[rear].idx=rear;
        queue[rear].type=type;
        queue[rear].wait_time=0;
        cust_num++;
    }
}
struct cust deQueue(){
    struct cust tmp;
    if(isEmpty()){
        printf("hahahahhhhhhh\n");
    }
    else{
        tmp.idx=queue[font].idx;
        tmp.type=queue[font].type;
        tmp.wait_time=queue[font].wait_time;
        cust_num--;
        font=(font+1)%maxsize;
        return tmp;
    }
}
int service(){
    //结算上一轮的service_time
    for(int i=1;i<=5;i++){
        if(winline[i].isOccupied==1){
            winline[i].service_time--;
            if(winline[i].service_time==0){
                winline[i].isOccupied=0;
            }
        }
    }
    //获取客户离开队伍
    for(int i=1;i<=5;i++){
        if(isEmpty()){
            return 0;
        }
        if(winline[i].isOpen==1&&winline[i].isOccupied==0){
            winline[i].isOccupied=1;
            struct cust tmp=deQueue();
            winline[i].service_time=tmp.type;
            printf("%d : %d\n",tmp.idx,tmp.wait_time);
        }
    }
    //bank优先:尽量减少窗口
    while((cust_num/win_num)<7&&win_num>win_num_min){
        winline[win_num--].isOpen=0;
    }
    return 1;
}