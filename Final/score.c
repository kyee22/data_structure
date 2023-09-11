#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

int main(){
    double total=0.0,name[100][100],s[100],w[100],weight=0.0;
    FILE *out=fopen("out.txt","w");
    int i=0,j;
    while(~scanf("%s%lf%lf",name[i],&s[i],&w[i])){
        total+=s[i]*w[i];
        weight+=w[i++];
    }
    char s1[]="[科目]",s2[]="[成绩]",s3[]="[学分]";
    printf("%40s   %10s   %8s\n",s1,s2,s3);
    for(j=0;j<i;j++)fprintf(out,"%40s   %10f   %10f\n",name[j],s[j],w[j]),printf("%40s   %10f   %-10f\n",name[j],s[j],w[j]);;
    fprintf(out,"------------------------------------------------------------->加权平均分:%f\n",total/weight),
    printf("------------------------------------------------------------->加权平均分:%f\n",total/weight);
    return 0;
}