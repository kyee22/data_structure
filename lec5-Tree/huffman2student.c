//�ļ�ѹ��-Huffmanʵ��
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 32

struct tnode {					//Huffman���ṹ
	char c;		
	int weight;					//���ڵ�Ȩ�أ�Ҷ�ڵ�Ϊ�ַ������ĳ��ִ���
	struct tnode *left,*right;
} ; 
int Ccount[128]={0};			//���ÿ���ַ��ĳ��ִ�������Ccount[i]��ʾASCIIֵΪi���ַ����ִ��� 
struct tnode *Root=NULL; 		//Huffman���ĸ��ڵ�
char HCode[128][MAXSIZE]={{0}}; //�ַ���Huffman���룬��HCode['a']Ϊ�ַ�a��Huffman���루�ַ�����ʽ�� 
int Step=0;						//ʵ�鲽�� 
FILE *Src, *Obj;
	
void statCount();				//����1��ͳ���ļ����ַ�Ƶ��
void createHTree();				//����2������һ��Huffman�������ڵ�ΪRoot 
void makeHCode();				//����3������Huffman������Huffman����
void atoHZIP(); 				//����4������Huffman���뽫ָ��ASCII���ı��ļ�ת����Huffman���ļ�

void print1();					//�������1�Ľ��
void print2(struct tnode *p);	//�������2�Ľ�� 
void print3();					//�������3�Ľ��
void print4();					//�������4�Ľ��

int main()
{
	if((Src=fopen("input.txt","r"))==NULL) {
		fprintf(stderr, "%s open failed!\n", "input.txt");
		return 1;
	}
	if((Obj=fopen("output.txt","w"))==NULL) {
		fprintf(stderr, "%s open failed!\n", "output.txt");
		return 1;
	}
	scanf("%d",&Step);					//���뵱ǰʵ�鲽�� 
	
	statCount();						//ʵ�鲽��1��ͳ���ļ����ַ����ִ�����Ƶ�ʣ�
	(Step==1) ? print1(): 1; 			//���ʵ�鲽��1���	
	createHTree();						//ʵ�鲽��2�������ַ�Ƶ��������Ӧ��Huffman��
	(Step==2) ? print2(Root): 2; 		//���ʵ�鲽��2���	
	makeHCode();				   		//ʵ�鲽��3������RootΪ���ĸ���Huffman��������ӦHuffman����
	(Step==3) ? print3(): 3; 			//���ʵ�鲽��3���
	(Step>=4) ? atoHZIP(),print4(): 4; 	//ʵ�鲽��4����Huffman��������ѹ���ļ��������ʵ�鲽��4���	

	fclose(Src);
	fclose(Obj);

    return 0;
} 

//��ʵ�鲽��1����ʼ 

void statCount()
{
	Ccount[0]=1;

	char ch;
	while((ch=fgetc(Src))!=EOF){
		if(ch!='\n')Ccount[ch]++;
	}
}

//��ʵ�鲽��1������

//��ʵ�鲽��2����ʼ
struct tnode **list=NULL;
int total=0,headPos=0;//headPosΪ˳�����Ԫ�ص��±�
int cmp(const void *p,const void *q){
	struct tnode **a=(struct tnode **)p;
	struct tnode **b=(struct tnode **)q;
	if((*a)->weight!=(*b)->weight)return (*a)->weight-(*b)->weight;
	else return (*a)->c-(*b)->c;

}
void add2List(struct tnode *p){		//��֤����Ĳ���
	int w=p->weight;
	if(total==0){//����
		list[headPos+0]=p;
		return;
	}
	for(int i=total-1+headPos;i>=0+headPos;i--){//bug��total=0,���б�Ϊ��ʱ,�ǲ������ѭ����
		if(w<list[i]->weight){
			list[i+1]=list[i];
			list[i]=p;
		}
		else{
			list[i+1]=p;
			break;
		}
	}
	total++;
}
void createHTree()
{
	list=(struct tnode **)malloc(200000*sizeof(struct tnode *));//�����б�

	/*  step 2.1: ����ɭ��   */
	struct tnode *p;
	for(int i=0;i<128;i++){
		if(Ccount[i]>0){
			p=(struct tnode *)malloc(sizeof(struct tnode));
			p->c=i;
			p->weight=Ccount[i];
			p->left=p->right=NULL;

			list[total++]=p;
		}
	}
	/*   step 2.2: ����   */
	qsort(list,total,sizeof(struct tnode *),cmp);
    // for(int i=0;i<total;i++)printf("%c:%d\n",list[i]->c,list[i]->weight);

	/*   step 2.3: ����Huffman��   */
    while(total>1){
		struct tnode *new=(struct tnode *)malloc(sizeof(struct tnode));
		new->weight=list[headPos]->weight+list[headPos+1]->weight;
		new->left=list[headPos+0];
		new->right=list[headPos+1];
		headPos+=2;
		total-=2;
		// printf("headPos:%d   total:%d    %d\n",headPos,total,new->weight);
		// if(total==0){
		// 	Root=new;
		// 	break;
		// }
		add2List(new);
	}
	Root=list[headPos];
}
//��ʵ�鲽��2������

//��ʵ�鲽��3����ʼ
char path[MAXSIZE];
void visit(struct tnode *p,char code,int depth){
	if(depth>1)path[depth-2]=code;//ǰ��

	if(p->left==NULL&&p->right==NULL){//�ݹ�߽磺Ҷ�ڵ�
		path[depth-1]='\0';
		strcpy(HCode[p->c],path);
	}
	else{
		visit(p->left,'0',depth+1);
		visit(p->right,'1',depth+1);
	}
}
void makeHCode()
{

	visit(Root,'0',1);
	
} 

//��ʵ�鲽��3������

//��ʵ�鲽��4����ʼ

void atoHZIP()
{
	int i=0,end=0,ch;
	unsigned char hch=0,*pBit=NULL;

	 /*   ����Step 1�Ѿ�����Src, ������Ҫ���µ���offset   */
	fseek(Src,0, SEEK_SET);

	do{

		ch=fgetc(Src);
		if(ch==EOF){
			ch=0;
			end=1;
		}
		
		for(pBit=HCode[ch];(*pBit)!='\0';pBit++){
			hch=(hch<<1)|(*pBit-'0');
			i++;
			if(i==8){
				fputc(hch,Obj);
				printf("%x",hch);

				i=0;//�ջ�
				hch=0;
			}
		}

		if(end&&i){
			while(i++<8)hch=(hch<<1);

			fputc(hch,Obj);
			printf("%x",hch);
		}

	}while(!end);
	
}

//��ʵ�鲽��4������

void print1()
{
	int i;
	printf("NUL:1\n");
	for(i=1; i<128; i++)
		if(Ccount[i] > 0)
			printf("%c:%d\n", i, Ccount[i]);
}

void print2(struct tnode *p)
{
	if(p != NULL){
		if((p->left==NULL)&&(p->right==NULL)) 
			switch(p->c){
				case 0: printf("NUL ");break;
				case ' ':  printf("SP ");break;
				case '\t': printf("TAB ");break;
				case '\n':  printf("CR ");break;
				default: printf("%c ",p->c); break;
			}
		print2(p->left);
		print2(p->right);
	}
}

void print3()
{
	int i;
	
	for(i=0; i<128; i++){
		if(HCode[i][0] != 0){
			switch(i){
				case 0: printf("NUL:");break;
				case ' ':  printf("SP:");break;
				case '\t': printf("TAB:");break;
				case '\n':  printf("CR:");break;
				default: printf("%c:",i); break;
			}
			printf("%s\n",HCode[i]);
		}
	}
} 

void print4()
{
	long int in_size, out_size;
	
	fseek(Src,0,SEEK_END);
	fseek(Obj,0,SEEK_END);
	in_size = ftell(Src);
	out_size = ftell(Obj);
	
	printf("\nԭ�ļ���С��%ldB\n",in_size);
	printf("ѹ�����ļ���С��%ldB\n",out_size);
	printf("ѹ���ʣ�%.2f%%\n",(float)(in_size-out_size)*100/in_size);
}
