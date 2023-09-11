#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

int cmp_time;

int binSearch(int list[],int target,int num){
    int low=0,high=num-1,mid;
    cmp_time=0;
    while(low<=high){
        mid=(low+high)/2;
        printf("pos:%d    elem:list[%d]=%d\n",mid,mid,list[mid]);
        cmp_time++;
        int cond=list[mid]-target;
        if(cond==0){
            printf("cmp_time:%d\n",cmp_time);
            return cmp_time;
        }
        else if(cond<0){
            low=mid+1;
        }
        else if(cond>0){
            high=mid-1;
        }
    }
    printf("cmp_time:%d\n",cmp_time);
    return 0;

}
int main(){
    int list[]={13,38,49,65,76,97};
    int list2[]={2,4,6,8,10,12,14,16,18,20};
    int list3[]={2,4,6,8,10,12,14,16,18};
    /*   功能1:求查找过程中比较次数   */
    /*   功能2:记录查找过程中比较过数组元素的下标   */
    binSearch(list,47,6);
    binSearch(list2,12,10);
    /*   功能3:求ACL   */
    int ACL=0;
    for(int i=0;i<9;i++){
        ACL+=binSearch(list3,list3[i],9);
    }
    printf("ACL:%d\n",ACL);
    

    return 0;
}