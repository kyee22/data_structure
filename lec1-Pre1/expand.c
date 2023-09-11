#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
char s[100000],ans[100000];
int i,j;

int main()
{
    gets(s);
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='-'){
            if('a'<=s[i-1]&&s[i-1]<='z'&&'a'<=s[i+1]&&s[i+1]<='z'&&s[i-1]<s[i+1]){
                for(char k=s[i-1]+1;k<s[i+1];k++){
                    ans[j++]=k;
                }
            }
            else if('A'<=s[i-1]&&s[i-1]<='Z'&&'A'<=s[i-1]&&s[j+1]<='Z'&&s[i-1]<s[i+1]){
                for(char k=s[i-1]+1;k<s[i+1];k++){
                    ans[j++]=k;
                }
            }
            else if('0'<=s[i-1]&&s[i-1]<='9'&&'0'<=s[i+1]&&s[i+1]<='9'&&s[i-1]<s[i+1]){
                for(char k=s[i-1]+1;k<s[i+1];k++){
                    ans[j++]=k;
                }
            }
            else ans[j++]=s[i];
        }
        else{
            ans[j++]=s[i];
        }
    }
    ans[j]='\0';
    puts(ans);

	return 0;
}
