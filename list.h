//
// Created by zhangsx on 2017/8/3.
//

#ifndef UNTITLED_SERVER_H
#define UNTITLED_SERVER_H

#endif //UNTITLED_SERVER_H
#define LIST_START_HEAD 0
#define LIST_START_TAIL 1
typedef struct LIST_NODE{
    void* entry;
    struct LIST_NODE* prev;
    struct LIST_NODE* next;
} node;

typedef struct LIST{
    struct LIST_NODE *head;
    struct LIST_NODE *tail;
    unsigned long len;
    void (*free)(node *n);
} list;

typedef struct listIter{
    node *next;
    int direction;
}listIter;

list* listInit();
list* listAdd(list *l, void *v);
list* listDelNode(list *l, node *n);
node* listIterNext(listIter *iter);
listIter *listGetIter(list *list,int direction);