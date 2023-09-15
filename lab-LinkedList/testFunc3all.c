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
    printf("elementCount:%d\n",obj->elementCount);
}
LinkedList *createLinkedList(void) {

   LinkedList *p=(LinkedList*)malloc(sizeof(LinkedList));
   p->head=NULL;
   p->elementCount=0;
   return p;
};

void addElement2Tail(int newNodeValue, LinkedList *obj) {
    ListNode *p=(ListNode *)malloc(sizeof(ListNode));
    p->element=newNodeValue;
    p->next=NULL;
   if((obj->head)==NULL){
        obj->head=p;
   }
   else{
        ListNode *q=obj->head;
        for(;q->next;q=q->next){
            ;
        }
        q->next=p;
   }
   obj->elementCount++;
}

void addElement(int targetVal, int newNodeValue, LinkedList *obj) {
   ListNode *p=(ListNode *)malloc(sizeof(ListNode));
    p->element=newNodeValue;
    p->next=NULL;
   if(obj->head==NULL){
        obj->head=p;
   }
   else{
        ListNode *q=obj->head,*preq=NULL;
        for(;q;preq=q,q=q->next){
            if(q->element==targetVal){
                p->next=q->next;
                q->next=p;
                break;
            }
        }
        if(q==NULL){
            p->next=preq->next;
            preq->next=p;
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
void insertElement2pos(int index,int newNodeValue,LinkedList *obj){
    ListNode *p=obj->head,*q;
    for(int i=1;i<=index;i++,p=p->next){
        if(p->next==NULL){//add2tail
            break;
        }
    }
    q=(ListNode *)malloc(sizeof(ListNode));
    q->element=newNodeValue;
    q->next=NULL;

    q->next=p->next;
    p->next=q;
    
    obj->elementCount++;
}
void insertElement2ptr(ListNode *p,int newNodeValue,LinkedList *obj){
    ListNode *q=(ListNode *)malloc(sizeof(ListNode));
    q->element=newNodeValue;
    q->next=NULL;
    
    q->next=p->next;
    p->next=q;
    
    obj->elementCount++;
}
unsigned int deleteElement(int opcode, int targetVal, LinkedList *obj) {
    ListNode *p = NULL, *q = NULL;
    unsigned int deleteNum = 0,find=0;
    if (opcode == 1) {
        for (p = obj->head; p != NULL;) {
            if (p->element == targetVal) {
                if (p == obj->head) {
                    obj->head = p->next;
                    free(p);
                    p = obj->head;
                    obj->elementCount--;
                    deleteNum++;
                } 
                else {
                    q->next = p->next;
                    free(p);
                    p = q->next;
                    obj->elementCount--;
                    deleteNum++;
                }
            }
            else {
                q = p, p = p->next;
            }
        }
    } 
    else if (opcode == 2) {
        for (p = obj->head; p != NULL; q = p, p = p->next) {
            if (p->element == targetVal) {
                find=1;
                break;
            }
        }
        if(find){
            if (p == obj->head) {
                obj->head = obj->head->next;
                free(p);
                obj->elementCount--;
                deleteNum++;
            } 
            else {
                q->next = p->next;
                free(p);
                obj->elementCount--;
                deleteNum++;
            }
        }
    } 
    else if (opcode == 3) { 
        for (p = obj->head; p != NULL; q = p, p = p->next) {
            if (p->element <= targetVal) {
                find=1;
                break;
            }
        }
        if(find){
            if (p == obj->head) {
                obj->head = p->next;
                free(p);
                obj->elementCount--;
                deleteNum++;
            } 
            else {
                q->next = p->next;
                free(p);
                obj->elementCount--;
                deleteNum++;
            }
        }
    }
    else if (opcode == 4) {
        ListNode *tmp=NULL,*pretmp=NULL;
        for(p=obj->head;p!=NULL;q=p,p=p->next){
            if(p->element<=targetVal){
                find=1;
                pretmp=q;
                tmp=p;
            }
        }
        if(find){
            if(tmp==obj->head){
                obj->head=tmp->next;
                free(tmp);
                deleteNum++;
                obj->elementCount--;
            }
            else{
                pretmp->next=tmp->next;
                free(tmp);
                deleteNum--;
                obj->elementCount++;
            }
        }
    }
    return deleteNum;
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
    insertElement2pos(0,1027,StuLinkedList);
    insertElement2ptr(StuLinkedList->head,1026,StuLinkedList);
    insertElement2ptr(StuLinkedList->head->next,1028,StuLinkedList);
    insertElement2pos(2,1029,StuLinkedList);
    
    printLinkedList(StuLinkedList);

    return 0;
}
