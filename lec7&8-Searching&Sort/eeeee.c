#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

void adjust(int k[ ],int i,int n)

{

    int j,temp;

    temp=k[i];

    j=2*i+1;

    while(j<n){

        if(j<n-1 && k[j]<k[j+1])

            j++;
        if(temp>=k[j]) 

            break;

        k[(j-1)/2]=k[j];

        j=2*j+1;

    }

    k[(j-1)/2]=temp;

}
int main(){
    printf("plan.doc 202206171502\n");
    printf("test.c 202206120912\n");
    printf("data.xls 202206230907\n");
    printf("math.doc 202207021506\n");
    printf("report.ppt 202203260918\n");
    printf("plan.doc 202206051202\n");
    printf("plans.doc 202206171705");
    return 0;
}

