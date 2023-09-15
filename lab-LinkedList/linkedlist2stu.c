#include <stdio.h>
#include <stdlib.h>
#include "linkedlist2stu.h"

/*
 * typedef struct node {	// Node Object
 *      int element;
 *      struct node *next;
 * } ListNode;
 *
 * typedef struct List {	// LinkedList Object
 *     listNode *head;
 *     int elementCount;
 * } LinkedList;
 */

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
    q->next=NULL;

    q->next=obj->head;
    obj->head=q;

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
                deleteNum++;
                obj->elementCount--;
            }
        }
    }
    return deleteNum;
}


int peekElement(int index,LinkedList *obj){
    int pos=0,find=0;
    ListNode *p=obj->head;
    for(;p!=NULL;p=p->next,pos++){
        if(pos==index){
            find=1;
            break;
        }
    }
    if(find)return p->element;
    else return -1;
}

int replaceElement(int index,int newNodeValue,LinkedList *obj){
    int pos=0,find=0;
    ListNode *p=obj->head;
    for(;p!=NULL;p=p->next,pos++){
        if(pos==index){
            p->element=newNodeValue;
            find=1;
            break;
        }
    }
    if(find)return 1;
    else return -1;
}

/*
 * DO NOT MODIFY ANYTHING BELOW!
 */
int main(){
    judge();
}