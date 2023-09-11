#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

struct nodedddd{
    int isDire;
    char name[1000];
    char date[1000];
    struct nodedddd *son[1000];
    int num_of_son;
}node[2000];

int stack[10000],top=-1;

char line[10000];
void layerOrder(struct nodedddd *t){
    struct nodedddd *Queue[10000],*p;
    int front=0,rear=0;
    Queue[0]=t;
    while(front<=rear){
        p=Queue[front++];
        if(!p->isDire)printf("%s %s\n",p->name,p->date);
        int i=0;
        while(p->son[i]!=NULL){
            Queue[++rear]=p->son[i];
            i++;
        }
        
    }
}
int main(){

    FILE *in=fopen("in.txt","r");

    /*  step1   */
    fscanf(in,"%s",line);
    int len=strlen(line),num=0;
    for(int i=0;i<len;i++){
        if(isdigit(line[i])){
           num=line[i]-'0';

            while(1){
                i++;
                if(isdigit(line[i])){
                    num=num*10+line[i]-'0';
                }
                else{
                    i--;
                    break;
                }
            }

            if(top>=0){//栈不为空
                
                int pos=node[stack[top]].num_of_son;
                node[stack[top]].son[pos]=&node[num];
                node[stack[top]].num_of_son++;
            }

            // printf("%d\n",num);
        }
        else if(line[i]=='('){
            top++;
            stack[top]=num;
        }
        else if(line[i]==','){
            continue;
        }
        else if(line[i]==')'){
            top--;
        }
    }
    // printf("******%d\n",node[101].num_of_son);


    /*   step2   */
    int id;
    int isDire;
    char name[1000];
    char date[1000];

    int xx=0,root;
    while(~fscanf(in," %d %s %d %s",&id,name,&isDire,date)){
        if(xx==0)root=id;

        xx++;

        node[id].isDire=isDire;
        strcpy(node[id].name,name);
        strcpy(node[id].date,date);

        // printf(" %d %s %d %s\n",id,name,isDire,date);
    }

    /*  step3  */
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char block[10000],newdate[1000];
        int level=0;
        char word[1000];int x=0;
        char path[1000][1000];

        scanf(" %s %s",block,newdate);
        // int lenee=strlen(block);
        // for(int j=0;j<lenee;j++){
        //     if(block[j]=='\\'){
        //         path[level][x]='\0';
        //         level++;
        //         x=0;
        //     }
        //     else{
        //         path[level][x++]=block[j];
        //     }
        // }
        // for(int k=0;k<=level;k++)printf("%s\n",path[k]);

        // struct nodedddd *cur=&node[root];
        // int n,m;
        // for(n=1;n<=level;n++){
        //     int flag=0;
        //     for(m=0;m<cur->num_of_son;m++){
        //         if(stcmp(path[n],cur->son[m]->name)==0){
        //             cur=cur->son[m];
        //             flag=1;
        //             break;
        //         }
        //     }
        //     if(!flag||(cur->son[0]==NULL))break;
        // }
        // while(n<=level){
        //      struct nodedddd *q=malloc(sizeof(struct nodedddd));
        //      q->
        //      int pos=cur->num_of_son;
        //      cur->son[pos]=q;
        // }


        // cur->num_of_son
    }
    layerOrder(&node[root]);
    return 0;
}