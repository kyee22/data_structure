#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

int main(){
    struct stu{
        char name[20];
        struct{
            int year;
            int month;
        }birth;
    };
    struct stu wangkai;
    wangkai.birth.year=2003;
    wangkai.birth.month=12;
    printf("%d %d\n",wangkai.birth.year,wangkai.birth.month);

    return 0;
}