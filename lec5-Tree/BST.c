#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
struct node{
    int data;
    int depth;
    struct node *left;
    struct node *right;
};
void visit(struct node *p){
    if(p->left==NULL&&p->right==NULL){
        printf("%d %d\n",p->data,p->depth);
    }
}
void inOrder(struct node *p){
    if(p!=NULL){
        inOrder(p->left);
        visit(p);
        inOrder(p->right);
    }
}
struct node *insert(struct node *p,int item,int d){
    if(p==NULL){
        p=(struct node *)malloc(sizeof(struct node));
        p->data=item;
        p->depth=d;
        p->left=p->right=NULL;
    }
    else if(item<p->data){
        p->left=insert(p->left,item,d+1);
    }
    else if(item>=p->data){
        p->right=insert(p->right,item,d+1);
    }
    return p;
}
int cmp_time;

int main(){
    int item,n;
    struct node *root=NULL;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&item);
        root=insert(root,item,1);
    }
    struct node *p=root;
    while(1){
        cmp_time++;
        if(p->data==62){
            break;
        }
        else if(p->data<62){
            p=p->right;
        }
        else if(p->data>62){
            p=p->left;
        }
    }
    printf("%d\n",cmp_time);
    return 0;
}

    