#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

int map[30][30],sum_line[30],sum_column[30];

int isvalid(int n){     //判断棋子是否在棋盘上
    if(1<=n&&n<=19)return 1;
    else return 0;
}

int main(){
    for(int i=1;i<=19;i++)
    for(int j=1;j<=19;j++){
        scanf("%d",&map[i][j]);
        if(map[i][j]!=0){
            sum_line[i]++;
            sum_column[j]++;
        }
    }
    //1:search lines
    for(int i=1;i<=19;i++){
        if(sum_line[i]<4)
            continue;
        for(int j=1;j<=19;j++){
            if(map[i][j]==0)
                continue;
            int color=map[i][j],cnt=0,needle=j;
            for(;needle<=19;needle++){
                if(map[i][needle]!=color){
                    break; 
                }
                else{
                    cnt++;
                }
            }
            if(cnt<4){
                j=needle-1;
            }
            else if(cnt==4){
                if((isvalid(j-1)&&map[i][j-1]==0)||(isvalid(needle)&&map[i][needle]==0)){
                    printf("%d:%d,%d\n",color,i,j);
                    return 0;
                }
                else{
                    j=needle-1;
                }
            }

        }
    }
    //2:search columns
    for(int j=1;j<=19;j++){
        if(sum_column[j]<4)
            continue;
        for(int i=1;i<=19;i++){
            if(map[i][j]==0)
                continue;
            int color=map[i][j],cnt=0,needle=i;
            for(;needle<=19;needle++){
                if(map[needle][j]!=color){
                    break; 
                }
                else{
                    cnt++;
                }
            }
            if(cnt<4){
                i=needle-1;
            }
            else if(cnt==4){
                if((isvalid(i-1)&&map[i-1][j]==0)||(isvalid(needle)&&map[needle][j]==0)){
                    printf("%d:%d,%d\n",color,i,j);
                    return 0;
                }
                else{
                    i=needle-1;
                }
            }
        }
    }
    //3:search diagonals from right_up corner
    for(int i,j,x=1;x<=37;x++){
        //initialize
        if(1<=x&&x<=19){
            i=1;
            j=20-x;
        }
        else if(20<=x&&x<=37){
            i=x-18;
            j=1;
        }
        //search
        for(;isvalid(i)&&isvalid(j);i++,j++){
            if(map[i][j]==0)
                continue;
            int color=map[i][j],cnt=0,needle_x=i,needle_y=j;
            for(;isvalid(needle_x)&&isvalid(needle_y);needle_x++,needle_y++){
                if(map[needle_x][needle_y]!=color){
                    break;
                }
                else{
                    cnt++;
                }
            }
            if(cnt<4){
                i=needle_x-1;
                j=needle_y-1;
            }
            else if(cnt==4){
                if((isvalid(i-1)&&isvalid(j-1)&&map[i-1][j-1]==0)||(isvalid(needle_x)&&isvalid(needle_y)&&map[needle_x][needle_y]==0)){
                    printf("%d:%d,%d\n",color,i,j);
                    return 0;
                }
                else{
                    i=needle_x-1;
                    j=needle_y-1;
                }
            }
        }

    }
    //4:search diagonals from left_up corner
    for(int i,j,x=1;x<=37;x++){
        //initialize
        if(1<=x&&x<=19){
            i=1;
            j=x;
        }
        else if(20<=x&&x<=37){
            i=x-18;
            j=19;
        }
        //search
        for(;isvalid(i)&&isvalid(j);i++,j--){
            if(map[i][j]==0)
                continue;
            int color=map[i][j],cnt=0,needle_x=i,needle_y=j;
            for(;isvalid(needle_x)&&isvalid(needle_y);needle_x++,needle_y--){
                if(map[needle_x][needle_y]!=color){
                    break;
                }
                else{
                    cnt++;
                }
            }
            if(cnt<4){
                i=needle_x-1;
                j=needle_y+1;
            }
            else if(cnt==4){
                if((isvalid(i-1)&&isvalid(j+1)&&map[i-1][j+1]==0)||(isvalid(needle_x)&&isvalid(needle_y)&&map[needle_x][needle_y]==0)){
                    printf("%d:%d,%d\n",color,i,j);
                    return 0;
                }
                else{
                    i=needle_x-1;
                    j=needle_y+1;
                }
            }
        }
    }
    //5:failed to search
    printf("No\n");
    return 0;
    
}
