#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

int main(){
    int num;
    char s1[10]="",s2[10]="";
    scanf("%d",&num);
    while(num--){
        scanf("%s%s",s1,s2);
        if(strcmp(s1,s2)==0){
            printf("Tie\n");
            continue;
        }

        if(strcmp(s1,"Rock")==0){
            if(strcmp(s2,"Scissors")==0)printf("Player1\n");
            else printf("Player2\n");
        }
        else if(strcmp(s1,"Scissors")==0){
            if(strcmp(s2,"Rock")==0)printf("Player2\n");
            else printf("Player1\n");
        }
        else if(strcmp(s1,"Paper")==0){
            if(strcmp(s2,"Rock")==0)printf("Player1\n");
            else printf("Player2\n");
        }
    }
    return 0;
}