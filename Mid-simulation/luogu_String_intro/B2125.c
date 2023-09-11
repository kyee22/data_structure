#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
struct stu{
    char name[1000];
    int score;
}rank[10000];
int cmp(const void *p,const void *q){
    struct stu *a=(struct stu *)p;
    struct stu *b=(struct stu *)q;
    return a->score-b->score;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %s",&rank[i].score,rank[i].name);
    }
    qsort(rank,n,sizeof(struct stu),cmp);
    printf("%s\n",rank[n-1].name);
    return 0;
}