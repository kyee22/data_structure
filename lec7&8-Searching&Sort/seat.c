#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
int find[1000];
struct item{
    int stuid;
    char stuname[50];
    int seat;
}tab[1000];

int cmp1(const void *p,const void *q){
    struct item *a=(struct item *)p;
    struct item *b=(struct item *)q;
    if(a->seat!=b->seat)return a->seat-b->seat;
    else return a->stuid-b->stuid;
}

int cmp2(const void *p,const void *q){
    struct item *a=(struct item *)p;
    struct item *b=(struct item *)q;
    return a->stuid-b->stuid;
}

int main(){
    FILE *in=fopen("in.txt","r"),*out=fopen("out.txt","w");
    int N,M=-1,Q,m=-1;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        fscanf(in,"%d %s %d",&tab[i].stuid,tab[i].stuname,&tab[i].seat);
        if(tab[i].seat>M)M=tab[i].seat;
    }

    qsort(tab,N,sizeof(struct item),cmp1);
    // printf("00000000\n");
    // for(int i=0;i<N;i++){
    //     printf("%d %s %d\n",tab[i].stuid,tab[i].stuname,tab[i].seat);
    // }
    Q=min(N,M);
    int rear=N-1;
    for(int targetSeat=1;targetSeat<=Q;targetSeat++){
        for(int i=0;i<N;i++){
            if(tab[i].seat==targetSeat){
                find[targetSeat]=1;
                break;
            }
        }
    }
    for(int i=1;i<=Q;i++){
        if(!find[i]){
            if(i>tab[rear].seat)break;
            tab[rear].seat=i;
            rear--;
        }
    }
    // printf("11111111111\n");
    // for(int i=0;i<N;i++){
    //     printf("%d %s %d\n",tab[i].stuid,tab[i].stuname,tab[i].seat);
    // }

    qsort(tab,N,sizeof(struct item),cmp1);
    for(int i=0;i<N;i++){
        if(tab[i].seat>m)m=tab[i].seat;
    }
    int delta=1;
    for(int i=1;i<N;i++){
        if(tab[i].seat==tab[i-1].seat){
            tab[i].seat=m+delta;
            delta++;
        }
    }


    qsort(tab,N,sizeof(struct item),cmp2);
    for(int i=0;i<N;i++){
        fprintf(out,"%d %s %d\n",tab[i].stuid,tab[i].stuname,tab[i].seat);
    }
    return 0;
}