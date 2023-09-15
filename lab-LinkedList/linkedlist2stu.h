//
// Created by 邹羽洋 on 2022-04-30.
//

#ifndef LINKEDLISTBASIC_LINKEDLIST2STU_H
#define LINKEDLISTBASIC_LINKEDLIST2STU_H
#pragma once
typedef struct node {
    int element;
    struct node *next;
} ListNode;

typedef struct List {
    ListNode *head;
    int elementCount;
} LinkedList;

void judge();
LinkedList *createLinkedList(void);
void addElement(int targetVal, int newNodeValue, LinkedList *obj);
void addElement2Tail(int newNodeValue, LinkedList *obj);
void addElement2Head(int newNodeValue, LinkedList *obj);
unsigned int deleteElement(int opcode, int targetVal, LinkedList *obj);
int peekElement(int index,LinkedList *obj);
int replaceElement(int index,int newNodeValue,LinkedList *obj);

#endif