#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
#define maxsize 100
int stack[maxsize],top=-1,op,elem;
int main(){
    while(~scanf("%d",&op)){
        if(op==1){
            scanf("%d",&elem);

            if(top==(maxsize-1)){
                printf("error ");
            }
            else{
                stack[++top]=elem;
            }
        }
        else if(op==0){
            if(top==-1){
                printf("error ");
            }
            else{
                printf("%d ",stack[top--]);
            }
        }
        else if(op==-1){
            break;
        }
    }

    return 0;
}