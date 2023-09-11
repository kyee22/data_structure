#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
int comp(const void *p1, const void *p2) {
    char *a = (char *)p1; //将p1强制转换为char*类型的指针
    char *b = (char *)p2; //将p2强制转换为char*类型的指针
    return strcmp(a, b); //返回两个字符串的字典序大小
}
int main(){
    char line[110][110];
    int i=0;
    while(scanf("%s",line[i])!=EOF)i++;    
    qsort(line,i,sizeof(line[0]),comp);
    for(int j=0;j<i;j++)puts(line[j]);
    
    return 0;
}