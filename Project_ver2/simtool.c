#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long

#define NHASH 2807303
#define MULT 2807239

#define NHASH2  3001
#define MULT2  571

unsigned int hash2(char *str){
       unsigned int h=0;
       char *p;

       for(p=str; *p!='\0'; p++)
              h = MULT2*h + *p;
       return h % NHASH2;
}
struct HashNode2{
    char word[1000];
    struct HashNode2*next;
}* HashTab2[NHASH2];
int hashSearch2(char s[],int create);

int calDistance(char s1[],char s2[],int len);

char name[100];
struct page1{
    char name[100];
    int weight[10010];
    char fingerprint[150];
}existingPage[20000];

struct page2{
    char name[100];
    int weight[10010];
    char fingerpint[150];
    int num0,num1,num2,num3;
    char repeat_h0[1000][100];
    char repeat_h1[1000][100];
    char repeat_h2[1000][100];
    char repeat_h3[1000][100];
}newPage[2000];

char hashvalue[10010][150];
char *getFingerprint(int weight[],int M,int N);

struct HashNode{
    char word[100];
    int pos;
    struct HashNode *next;
}*HashTab[NHASH];
unsigned int hash(char *str);
int hashSearch(char s[],int create,int pos_in_vector);//将前N个特征单词存入hash表(参数create=1). 然后在hash表中寻找(参数create=0):
                                        //找到,返回这个词在向量中的下标i,并且权重weight[page][i]++;否则,返回-1

char word[100];                       //词频统计后,前序遍历时用于生成单词(单词和频率存入featureVector)

struct feature{                         //特征
    char Word[100];
    int time;
}featureVector[209000];                  //特征向量
int num_of_feature;                     //用作下标为特征向量计数


struct TrieNode{                        //以下是trie树要用到的函数
    char ch;
    int count;
    struct TrieNode *child[26];
}*root=NULL;

struct TrieNode* talloc();
void add2Tree(char *s);
void visit(struct TrieNode *p,int level);
void preOrder(struct TrieNode *p,int level);
                                        //以上是trie树要用到的函数

char StopWord[10000][100];
int findStopWord(char *s,int num);      //找到,返回1;否则,返回0

char tmp_word[100],tmp_ch;
int cnt;                                //用于输入时getword

int cmp(const void *p,const void *q);

int main(int argc,char *argv[]){
    int N,M;
    N=atoi(argv[1]),M=atoi(argv[2]);
    
    // scanf("%d%d",&N,&M);
    FILE *pSW=fopen("stopwords.txt","r");
    FILE *pAt=fopen("article.txt","r");
    FILE *pHV=fopen("hashvalue.txt","r");
    FILE *pSP=fopen("sample.txt","r");
    FILE *pOUT=fopen("result.txt","w");
    /*  获得StopWord列表和hasevalue列表   */
    int num_of_stopword=0;
    while(~fscanf(pSW,"%s",StopWord[num_of_stopword])){
        hashSearch2(StopWord[num_of_stopword],1);
        num_of_stopword++;
    }

    int num_of_hashvalue=0;
    while(~fscanf(pHV,"%s",hashvalue[num_of_hashvalue++]));


    /*   获得特征向量(词频最高的N个单词列表)   */
    //   用Trie树实现词频统计
    root=talloc();
    root->count=0;

    fseek(pAt,0, SEEK_SET);
    while(~fscanf(pAt,"%c",&tmp_ch)){
        if (isalpha(tmp_ch)){
            tmp_word[cnt++]=tolower(tmp_ch);
        }
        else{
            if(!cnt){
                continue;
            }
            tmp_word[cnt]='\0';
            if(!hashSearch2(tmp_word,0)){
                add2Tree(tmp_word);
            }
            cnt=0;
        }
    }
    preOrder(root,-1);
    qsort(featureVector,num_of_feature,sizeof(struct feature),cmp);
    // for(int i=0;i<N;i++)printf("%d :%-20s %d\n",i,featureVector[i].Word,featureVector[i].time);

    /*   计算fingerprint   */

    //将前N个单词添加到hash表
    for(int i=0;i<N;i++)hashSearch(featureVector[i].Word,1,i);

    //分别读artcle的各个网页
    fseek(pAt,0, SEEK_SET);
    int top1=0;
    cnt=0;
    fscanf(pAt,"%s",name);
    strcpy(existingPage[top1].name,name);
    while(~fscanf(pAt,"%c",&tmp_ch)){
        if (isalpha(tmp_ch)){
            tmp_word[cnt++]=tolower(tmp_ch);
        }
        else if(cnt){
            tmp_word[cnt]='\0';
            if(!hashSearch2(tmp_word,0)){
                int value;
                if((value=hashSearch(tmp_word,0,-1))!=-1){
                    existingPage[top1].weight[value]++;
                }
            }
            cnt=0;
        }

        if(tmp_ch=='\f'){
            if(fscanf(pAt," %s",name)==EOF)break;
            top1++;
            strcpy(existingPage[top1].name,name);
        }
    }
    //分别读sample的各个网页,方法同上
    fseek(pSP,0, SEEK_SET);
    int top2=0;
    cnt=0;
    fscanf(pSP,"%s",name);
    strcpy(newPage[top2].name,name);
    while(~fscanf(pSP,"%c",&tmp_ch)){
        if (isalpha(tmp_ch)){
            tmp_word[cnt++]=tolower(tmp_ch);
        }
        else if(cnt){
            tmp_word[cnt]='\0';
            if(!hashSearch2(tmp_word,0)){
                int value;
                if((value=hashSearch(tmp_word,0,-1))!=-1){
                    newPage[top2].weight[value]++;
                }
            }
            cnt=0;
        }
        if(tmp_ch=='\f'){
            if(fscanf(pSP," %s",name)==EOF)break;
            top2++;
            strcpy(newPage[top2].name,name);
        }
    }
    //计算指纹
    for(int i=0;i<=top1;i++){
        strcpy(existingPage[i].fingerprint,getFingerprint(existingPage[i].weight,M,N));
    }
    for(int i=0;i<=top2;i++){
        strcpy(newPage[i].fingerpint,getFingerprint(newPage[i].weight,M,N));
    }
    //计算汉明距离并录入到结构体数组中
    for(int i=0;i<=top2;i++){
        for(int j=0;j<=top1;j++){
            switch (calDistance(newPage[i].fingerpint,existingPage[j].fingerprint,M))
            {
                case 0:
                    strcpy(newPage[i].repeat_h0[newPage[i].num0],existingPage[j].name);newPage[i].num0++;
                    break;
                case 1:
                    strcpy(newPage[i].repeat_h1[newPage[i].num1],existingPage[j].name);newPage[i].num1++;
                    break;
                case 2:
                    strcpy(newPage[i].repeat_h2[newPage[i].num2],existingPage[j].name);newPage[i].num2++;
                    break;
                case 3:
                    strcpy(newPage[i].repeat_h3[newPage[i].num3],existingPage[j].name);newPage[i].num3++;
                    break;
                default:
                    break;
            }
        }
    }
    /*   输出   */
    for(int i=0;i<=top2;i++){
        fprintf(pOUT,"%s\n",newPage[i].name);
        if(newPage[i].num0){
            fprintf(pOUT,"0:");
            for(int j=0;j<newPage[i].num0;j++){
                fprintf(pOUT,"%s ",newPage[i].repeat_h0[j]);
            }
            fprintf(pOUT,"\n");
        }
        if(newPage[i].num1){
            fprintf(pOUT,"1:");
            for(int j=0;j<newPage[i].num1;j++){
                fprintf(pOUT,"%s ",newPage[i].repeat_h1[j]);
            }
            fprintf(pOUT,"\n");
        }
        if(newPage[i].num2){
            fprintf(pOUT,"2:");
            for(int j=0;j<newPage[i].num2;j++){
                fprintf(pOUT,"%s ",newPage[i].repeat_h2[j]);
            }
            fprintf(pOUT,"\n");
        }
        if(newPage[i].num3){
            fprintf(pOUT,"3:");
            for(int j=0;j<newPage[i].num3;j++){
                fprintf(pOUT,"%s ",newPage[i].repeat_h3[j]);
            }
            fprintf(pOUT,"\n");
        }
    }
    printf("%s\n",newPage[0].name);
    if(newPage[0].num0){
        printf("0:");
        for(int j=0;j<newPage[0].num0;j++){
            printf("%s ",newPage[0].repeat_h0[j]);
        }
        printf("\n");
    }
    if(newPage[0].num1){
        printf("1:");
        for(int j=0;j<newPage[0].num1;j++){
            printf("%s ",newPage[0].repeat_h1[j]);
        }
        printf("\n");
    }
    if(newPage[0].num2){
        printf("2:");
        for(int j=0;j<newPage[0].num2;j++){
            printf("%s ",newPage[0].repeat_h2[j]);
        }
        printf("\n");
    }
    if(newPage[0].num3){
        printf("3:");
        for(int j=0;j<newPage[0].num3;j++){
            printf("%s ",newPage[0].repeat_h3[j]);
        }
        printf("\n");
    }
    return 0;
}

int findStopWord(char *s,int num){
    int low=0,high=num-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        int cond=strcmp(StopWord[mid],s);
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

struct TrieNode* talloc(){
    struct TrieNode* p=(struct TrieNode*)malloc(sizeof(struct TrieNode));
    int i;

    p->count=0;
    for(i=0;i<26;i++)
        p->child[i]=NULL;
    return p;
}

void add2Tree(char *s){
    struct TrieNode *p;
    for(p=root;(*s)!='\0';s++){
        if(p->child[*s-'a']==NULL)
            p->child[*s-'a']=talloc();
        p->child[*s-'a']->ch=*s;
        p=p->child[*s-'a'];
    }
    p->count++;
}
void visit(struct TrieNode *p,int level){
    if(p!=NULL&&level>-1){
        word[level]=p->ch;
        if(p->count>0){
            word[level+1]='\0';
            strcpy(featureVector[num_of_feature].Word,word);
            featureVector[num_of_feature].time=p->count;
            num_of_feature++;
        }
    }
}
void preOrder(struct TrieNode *p,int level){
    if(p!=NULL){
        visit(p,level);
        for(int i=0;i<26;i++){
            preOrder(p->child[i],level+1);
        }
    }
}

int cmp(const void *p,const void *q){
    struct feature *a=(struct feature *)p;
    struct feature *b=(struct feature *)q;
    if(a->time!=b->time)return b->time-a->time;
    else return strcmp(a->Word,b->Word);
}

unsigned int hash(char *str){
       unsigned int h=0;
       char *p;

       for(p=str; *p!='\0'; p++)
            h = MULT*h + *p;
       return h % NHASH;
}

int hashSearch(char s[],int create,int pos_in_vector){
    unsigned int h=hash(s);
    struct HashNode *cur=NULL,*pre=NULL;
    int isfind=0;
    for(cur=HashTab[h];cur!=NULL;pre=cur,cur=cur->next){
        int cond=strcmp(cur->word,s);
        if(cond==0){
            isfind=1;
            break;
        }
    }
    if(isfind){
        return cur->pos;
    }
    else{
        if(create){
            struct HashNode *q=(struct HashNode*)malloc(sizeof(struct HashNode));
            strcpy(q->word,s);
            q->next=NULL;
            q->pos=pos_in_vector;

            if(HashTab[h]==NULL){//表为空
                HashTab[h]=q;
            }
            else{//表不为空
                q->next=HashTab[h];
                HashTab[h]=q;
            }
        }
        return -1;
    }
}
char *getFingerprint(int weight[],int M,int N){
    char *result=(char *)malloc(sizeof(char)*(M+10));
    int j;
    for(j=0;j<M;j++){
        long long temp=0;
        for(int i=0;i<N;i++){
            int sign=(hashvalue[i][j]=='1')?1:-1;
            temp+=sign*weight[i];
        }
        result[j]=(temp>0)?'1':'0';
    }
    result[j]='\0';
    return result;
}

int calDistance(char s1[],char s2[],int len){
    int tmp=0;
    for(int i=0;i<len;i++){
        if(s1[i]!=s2[i])tmp++;
    }
    return tmp;
}

int hashSearch2(char s[],int create){
    unsigned int h=hash2(s);
    struct HashNode2 *cur=NULL,*pre=NULL;
    int isfind=0;
    for(cur=HashTab2[h];cur!=NULL;pre=cur,cur=cur->next){
        int cond=strcmp(cur->word,s);
        if(cond==0){
            isfind=1;
            break;
        }
    }
    if(isfind){
        return 1;
    }
    else{
        if(create){
            struct HashNode2 *q=(struct HashNode2*)malloc(sizeof(struct HashNode2));
            strcpy(q->word,s);
            q->next=NULL;

            if(HashTab2[h]==NULL){//表为空
                HashTab2[h]=q;
            }
            else{//表不为空
                q->next=HashTab2[h];
                HashTab2[h]=q;
            }
        }
        return 0;
    }
}