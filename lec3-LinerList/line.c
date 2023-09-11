#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
LL line[1000][7],cnt,sum,checked[1000],max=-1,ans_x,ans_y,ans_rx,ans_ry;
int main(){
    scanf("%lld",&cnt);
    for(LL i=0;i<cnt;i++){
        scanf("%lld%lld%lld%lld",&line[i][1],&line[i][2],&line[i][3],&line[i][4]);
    }
    for(LL i=0;i<cnt;i++){
        if(checked[i]){
            continue;
        }
        LL right_x=line[i][3],right_y=line[i][4],ans=1;
        //往右边遍历
        for(LL x=0;x<cnt&&x!=i;x++){
            // if(checked[x]){
            //     continue;
            // }
            if(line[x][1]==right_x&&line[x][2]==right_y){//this line的左边接上last line的右边
                ans++;
                right_x=line[x][3];
                right_y=line[x][4];
                checked[x]=1;
                x=-1;//刷新needle再遍历
            }
        }
        //往左边遍历
        LL left_x=line[i][1],left_y=line[i][2];
        for(LL x=0;x<cnt&&x!=i;x++){
            // if(checked[x]){
            //     continue;
            // }
            if(line[x][3]==left_x&&line[x][4]==left_y){//this line的右边接上last line的左边
                ans++;
                left_x=line[x][1];
                left_y=line[x][2];
                checked[x]=1;
                x=-1;//刷新needle再遍历
            }
        }
        //更新ans
        if(ans>max){
            max=ans;
            ans_x=left_x;
            ans_y=left_y;
            ans_rx=right_x;
            ans_ry=right_y;
        }
    }
    printf("%lld %lld %lld\n",max,ans_x,ans_y);
    // printf("%lld %lld\n",ans_rx,ans_ry);
    return 0;
}
