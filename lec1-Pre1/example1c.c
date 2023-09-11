#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

char s[210000],sign[210000];
LL cnt1=0,cnt2=0,formula[210000],ans,cnt3;
int main()
{
    //input
    gets_s(s,210000-1);
    for(LL i=0;i<strlen(s)-1;i++){
        if(s[i]=='*'||s[i]=='+'||s[i]=='-'||s[i]=='/'){
            sign[cnt2++]=s[i];
        }
        else if('0'<=s[i]&&s[i]<='9'){
            LL tmp=s[i]-'0',j;
            for(j=i+1;'0'<=s[j]&&s[j]<='9'&&j<strlen(s);j++){
                tmp=tmp*10+s[j]-'0';
            }
            i=j-1;
            formula[cnt1++]=tmp;
        }
        else {;}
    }
    //calculate
    LL tmp=formula[0];
    for(LL i=0;i<cnt2;i++){
        if(sign[i]=='*'){
            tmp*=formula[i+1];
        }
        else if(sign[i]=='/'){
            tmp/=formula[i+1];
        }
        else if(sign[i]=='+'){
            ans+=tmp;
            tmp=formula[i+1];
//            printf("tmp:%lld  ans:%lld\n",tmp,ans);
        }
        else if(sign[i]=='-'){
            ans+=tmp;
            tmp=-1*formula[i+1];
        }
    }
    ans+=tmp;
    printf("%lld\n",ans);
//    for(int i=0;i<cnt1;i++)printf("%lld ",formula[i]);
//    printf("\n");
//    for(int i=0;i<cnt2;i++)printf("%c ",sign[i]);
    return 0;
}
