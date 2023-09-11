#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

struct node{
    int dir;
    int delta;
}stack[10000],ans[10000];




int top=-1;

int main(){
    int pair[100],i=1;
    pair[5]=6;pair[6]=5;pair[7]=8;pair[8]=7;
    int dir,delta;
    while(1){
        scanf(" %d",&dir);
        
        scanf("-%d",&delta);
        if(dir==0){
            break;
        }
        if(top<=-1||pair[dir]!=stack[top].dir){//栈为空,push
            top++;
            stack[top].dir=dir;
            stack[top].delta=delta;
        }
        else{
            if(pair[dir]==stack[top].dir){
                if(delta<stack[top].delta){
                    stack[top].delta-=delta;
                }
                else if(delta==stack[top].delta){
                    top--;
                }
                else if(delta>stack[top].delta){
                    int tmp=delta-stack[top].delta;
                    top--;

                    top++;
                    stack[top].dir=dir;
                    stack[top].delta=tmp;
                }
            }
        }

        // printf("%d:",i++);
        // for(int i=0;i<=top;i++)printf("%d-%d ",stack[i].dir,stack[i].delta);
        // printf("\n");

        // printf("%d %d\n",dir,delta);
    }
    
    int last_dir=stack[0].dir;

    int idx=0;
    ans[idx].dir=stack[0].dir;
    ans[idx].delta=stack[0].delta;

    for(int i=1;i<=top;i++){
        if(stack[i].dir==last_dir){
            ans[idx].delta+=stack[i].delta;
        }
        else{
            idx++;
            ans[idx].dir=stack[i].dir;
            ans[idx].delta=stack[i].delta;

            last_dir=stack[i].dir;
        }
    }
    for(int i=idx;i>=0;i--){
        printf("%d-%d ",pair[ans[i].dir],ans[i].delta);
    }
    return 0;
}