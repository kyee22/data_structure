#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
char arr1[90000000],arr2[90000000],ans[90000000];
LL cnt;

void reverse(char a[]){
    char tmp;
    for(LL i=0,j=strlen(a)-1;i<j;i++,j--){
        tmp=a[i];
        a[i]=a[j];
        a[j]=tmp;
    }
}

int main()
{
    scanf("%s",arr1);
    scanf("%s",arr2);

    /*  在*/
    LL i=0,j=0,flag=0;
    for(;arr1[i]!='\0';i++){
        if(arr1[i]!='0'||(flag&&arr1[i]=='0')){
            arr1[j++]=arr1[i];
            flag=1;
        }
    }
    arr1[j]='\0';
    i=0,j=0,flag=0;
    for(;arr2[i]!='\0';i++){
        if(arr2[i]!='0'||(flag&&arr2[i]=='0')){
            arr2[j++]=arr2[i];
            flag=1;
        }
    }
    arr2[j]='\0';

    /*   �Ƚ��������Ĵ�С   */
    LL len1=strlen(arr1),len2=strlen(arr2),case_mode=1;
    if(len1>len2){
        case_mode=1;
    }
    else if(len2>len1){
        case_mode=2;
    }
    else if(len1==len2){
        LL x;
        for(x=0;arr1[x]!='\0';x++){
            if(arr1[x]!=arr2[x])
                break;
        }
        if(x==len1)case_mode=3;
        else if(arr1[x]>arr2[x])case_mode=1;
        else case_mode=2;
    }

    /*   calculate   */
    //case1:
    if(case_mode==1){
        LL i,j;
        for(i=len1-1,j=len2-1;j>=0&&i>=0;i--,j--){
            while(arr1[i]<'0'){
                arr1[i]+=10;
                arr1[i-1]--;
            }

            if(arr1[i]>=arr2[j]){
                ans[cnt++]='0'+arr1[i]-arr2[j];
            }
            else{
                ans[cnt++]='0'+10+arr1[i]-arr2[j];
                arr1[i-1]--;
            }
        }
        for(;i>=0;i--){
             while(arr1[i]<'0'){
                arr1[i]+=10;
                arr1[i-1]--;
            }
            ans[cnt++]=arr1[i];
        }
        cnt--;
        //ɾ��ǰ��0
        while(1){
            if(ans[cnt]!='0')break;

            cnt--;
        }
        ans[++cnt]='\0';
    }
    //case2:
    else if(case_mode==2){
        LL i,j;
        for(i=len1-1,j=len2-1;j>=0&&i>=0;i--,j--){
            while(arr2[j]<'0'){
                arr2[j]+=10;
                arr2[j-1]--;
            }

            if(arr1[i]<=arr2[j]){
                ans[cnt++]='0'+arr2[j]-arr1[i];
            }
            else{
                ans[cnt++]='0'+10+arr2[j]-arr1[i];
                arr2[j-1]--;
            }
        }
        for(;j>=0;j--){
            while(arr2[j]<'0'){
                arr2[j]+=10;
                arr2[j-1]--;
            }
            ans[cnt++]=arr2[j];
        }
        cnt--;
        //ɾ��ǰ��0
        while(1){
            if(ans[cnt]!='0')break;

            cnt--;
        }
        ans[++cnt]='-';
        ans[++cnt]='\0';

    }
    //case3:
    else if(case_mode==3){
        printf("0\n");
        return 0;
    }
    reverse(ans);
    puts(ans);
	return 0;
}
