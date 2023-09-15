#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include "linkedlist2stu.h"

#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))
#define LL long long
void printLinkedList(LinkedList *obj){
    ListNode *p = obj->head;
    for(;p;p = p->next){
        printf("%d\n",p->element);
    }
}
LinkedList *createLinkedList(void) {

   LinkedList *p=(LinkedList*)malloc(sizeof(LinkedList));
   p->head=NULL;
   p->elementCount=0;
   return p;
};

void addElement2Tail(int newNodeValue, LinkedList *obj) {
   if((obj->head)==NULL){
        ListNode *p=(ListNode *)malloc(sizeof(ListNode));
        p->element=newNodeValue;
        p->next=NULL;
        obj->head=p;
   }
   else{
        ListNode *p=obj->head;
        for(;p->next;p=p->next){
            ;
        }
        ListNode *q=(ListNode *)malloc(sizeof(ListNode));
        q->element=newNodeValue;
        q->next=NULL;
        p->next=q;
   }
   obj->elementCount++;
}

void addElement(int targetVal, int newNodeValue, LinkedList *obj) {

   ListNode *p=(ListNode *)malloc(sizeof(ListNode)),*r=NULL;
   if(obj->head==NULL){//___sepcial judge: head==NULL
        p->element=newNodeValue;
        p->next=NULL;
        obj->head=p;
   }
   else{
        for(p=obj->head;p!=NULL;r=p,p=p->next){
            if(p->element==targetVal){//___success to search
                ListNode *q=(ListNode *)malloc(sizeof(ListNode));
                q->element=newNodeValue;
                q->next=p->next;
                p->next=q;
                break;//___only search the 1st one showing up, so break
            }
        }
        if(p==NULL){//___failed to search
            ListNode *q=(ListNode *)malloc(sizeof(ListNode));
            q->element=newNodeValue;
            q->next=NULL;
            r->next=q;
        }
   }
   obj->elementCount++;
}

void addElement2Head(int newNodeValue, LinkedList *obj) {
    ListNode *q=(ListNode *)malloc(sizeof(ListNode));
    q->element=newNodeValue;
    q->next=obj->head;
    obj->head=q;

    obj->elementCount++;
}

int peekElement(int index,LinkedList *obj){
    int pos=0,find=0;
    ListNode *p=obj->head;
    for(;p!=NULL;p=p->next){
        if(pos==index){
            find=1;
            break;
        }
        pos++;
    }
    if(find)return p->element;
    else return -1;
}

int replaceElement(int index,int newNodeValue,LinkedList *obj){
    int pos=0,find=0;
    ListNode *p=obj->head;
    for(;p!=NULL;p=p->next){
        if(pos==index){
            p->element=newNodeValue;
            find=1;
            break;
        }
        pos++;
    }
    if(find)return 1;
    else return -1;
}
int main(){
    printf("-----------------------------------\n");
    printf("-----------------------------------\n");
    LinkedList *StuLinkedList = createLinkedList();
    addElement2Tail(13,StuLinkedList);
    addElement2Tail(14,StuLinkedList);
    addElement2Tail(15,StuLinkedList);

    addElement(13,100,StuLinkedList);
    addElement(100,200,StuLinkedList);
    addElement(15,88,StuLinkedList);

    addElement2Head(999,StuLinkedList);
    addElement2Head(1025,StuLinkedList);

    printLinkedList(StuLinkedList);
    printf("-----------------------------------\n");
    printf("%d\n",peekElement(0,StuLinkedList));
    printf("%d\n",peekElement(5,StuLinkedList));
    printf("%d\n",peekElement(7,StuLinkedList));
    printf("-----------------------------------\n");
    replaceElement(0,1026,StuLinkedList);
    replaceElement(5,0,StuLinkedList);
    replaceElement(7,89,StuLinkedList);
    printLinkedList(StuLinkedList);
    return 0;
}
