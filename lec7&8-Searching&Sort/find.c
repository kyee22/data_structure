#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
/* compute hash value for string */

#define NHASH  3001
#define MULT  37
unsigned int hash(char *str){
       unsigned int h=0;
       char *p;

       for(p=str; *p!='\0'; p++)
              h = MULT*h + *p;
       return h % NHASH;
}
struct node{
    char word[1000];
    struct node*next;
}* HashTab[NHASH];

char dict[4000][1000];
int num,cmp_time,letterIndex[800],Count[800];
int linerSearch(char s[]){
    for(int i=0;i<num;i++){
        cmp_time++;
        int cond=strcmp(dict[i],s);
        if(cond==0){
            return 1;
        }
        else if(cond>0){
            return 0;
        }
    }
    return 0;
}

int binSearch(char s[]){
    int low=0,high=num-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        cmp_time++;
        int cond=strcmp(dict[mid],s);
        if(cond==0){
            return 1;
        }
        else if(cond<0){
            low=mid+1;
        }
        else if(cond>0){
            high=mid-1;
        }
    }
    return 0;

}


int indexSearch(char s[]){
    if(Count[s[0]]==0)return 0;

    int low=letterIndex[s[0]],high=letterIndex[s[0]]+Count[s[0]]-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        cmp_time++;
        int cond=strcmp(dict[mid],s);
        if(cond==0){
            return 1;
        }
        else if(cond<0){
            low=mid+1;
        }
        else if(cond>0){
            high=mid-1;
        }
    }
    return 0;
}


int hashSearch(char s[],int create){
    unsigned int h=hash(s);
    struct node *cur=NULL,*pre=NULL;
    int isfind=0;

    for(cur=HashTab[h];cur!=NULL;pre=cur,cur=cur->next){
        cmp_time++;
        int cond=strcmp(cur->word,s);
        if(cond==0){
            isfind=1;
            break;
        }
        else if(cond>0){
            isfind=0;
            break;
        }
    }
    if(isfind){
        return 1;
    }
    else{
        if(create){
            struct node *q=(struct node*)malloc(sizeof(struct node));
            strcpy(q->word,s);
            q->next=NULL;

            /*  保持字典序插入节点   */
            if(HashTab[h]==NULL){//表为空
                HashTab[h]=q;
            }
            else{//表不为空
                if(cur==HashTab[h]){
                    q->next=HashTab[h];
                    HashTab[h]=q;
                }
                else{
                    pre->next=q;
                    q->next=cur;
                }
                
            }
        }

        return 0;
    }
}

int main(){
    char s[1000];
    int op,isfind;
    FILE *in=fopen("dictionary3000.txt","r");
    while(fscanf(in,"%s",dict[num])!=EOF){
        if(Count[dict[num][0]]==0)letterIndex[dict[num][0]]=num;
        Count[dict[num][0]]++;

        hashSearch(dict[num],1);

        num++;
    }
    // for(char i='a';i<='z';i++)printf("%c %d\n",i,letterIndex[i]);
    scanf("%s%d",s,&op);

    cmp_time=0;//生成hash表时改变了cmp_time, 所以这里要收回
    
    switch (op){
        case 1:
            isfind=linerSearch(s);
            printf("%d %d\n",isfind,cmp_time);
            break;
        case 2:
            isfind=binSearch(s);
            printf("%d %d\n",isfind,cmp_time);
            break;
        case 3:
            isfind=indexSearch(s);
            printf("%d %d\n",isfind,cmp_time);
            break;
        case 4:
            isfind=hashSearch(s,0);
            printf("%d %d\n",isfind,cmp_time);
            break;        
        default:
            break;
    }
    fclose(in);
    return 0;
}