#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
#define maxsize 1000
struct {
    char caller[200];
    char callees[1000][200];
    int num_of_callees;
}map[1000];
struct {
    char funcName[200];
}stack[maxsize];

int top=-1,op,cnt=0;
char s[200];
void push(char s[]){
    top++;
    strcpy(stack[top].funcName,s);
}
void pop(){
    top--;
}
int isEmpty(){
    return top==-1;
}
int isFull(){
    return top==maxsize;
}
int main(){
    while(~scanf("%d",&op)){
        if(top==-1&&cnt>0){
            break;
        }

        if(op==8){
            //压栈
            scanf("%s",s);
            push(s);

            //初始化
            strcpy(map[cnt].caller,s);
            map[cnt].num_of_callees=0;
            cnt++;

            for(int x=0;x<cnt;x++){
                if(strcmp(map[x].caller,stack[top-1].funcName)==0){
                    int isRepeated=0;
                    for(int i=0;i<map[x].num_of_callees;i++){
                        if(strcmp(map[x].callees[i],s)==0){
                            isRepeated=1;
                            break;
                        }
                    }

                    if(isRepeated){
                        ;
                    }
                    else{
                        strcpy(map[x].callees[map[x].num_of_callees],s);
                        map[x].num_of_callees++;
                    }
                    break;
                }
            }
        }
        else if(op==0){
            pop();
        }
        if(top==-1&&cnt>0){
            break;
        }

    }
    for(int i=0;i<cnt;i++){
        if(map[i].num_of_callees>0){
            printf("%s:",map[i].caller);
            for(int j=0;j<map[i].num_of_callees;j++){
                printf(j==map[i].num_of_callees-1?"%s\n":"%s,",map[i].callees[j]);
            }
        }
    }
    
    return 0;
}