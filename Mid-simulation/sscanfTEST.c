#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

int main(){
    int return_value;
    char s[100]="";
    int data;
    gets(s);
    if(return_value=sscanf(s,"-%d",&data)){
        printf("case 1:succeed! \n");
        printf("return_value:%d   data:%d\n",return_value,data);
    }
    else{
        printf("case 1:failed! \n");
        printf("return_value:%d   data:%d\n",return_value,data);
    }
    
    if(return_value=sscanf(s,"%d",&data)){
        printf("case 2:succeed! \n");
        printf("return_value:%d   data:%d\n",return_value,data);
    }
    else{
        printf("case 2:failed! \n");
        printf("return_value:%d   data:%d\n",return_value,data);
    }
   
    return 0;
}