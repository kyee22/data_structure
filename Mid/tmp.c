#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

struct point {
    float x,y;
};

struct t{
    struct point a,b,c;
}tr;

struct node{
    int elem;
    struct node *next;
};
struct node list[200];
int main(){
    struct node *p=&list[10];
    printf("%d\n",p-list);

    return 0;
}