//
// Created by zhangsx on 2017/8/4.
//
#include <stdlib.h>
#include "list.h"

list* listInit(){
    list *l=NULL;
    l=malloc(sizeof(list));
    if(l==NULL)
        return NULL;
    l->head=l->tail=NULL;
    l->len=0;
    l->free=NULL;
    return l;
}
list *listAdd(list *l, void *v){
    node *node=NULL;
    node=malloc(sizeof(*node));
    if(node==NULL)
        return l;
    node->entry=v;
    if(l->len==0){
        l->head=l->tail=node;
        node->prev=node->next=NULL;
    }else{
        node->prev=l->tail;
        node->next=NULL;
        l->tail->next=node;
        l->tail=node;
    }
    l->len++;
    return l;
}
list *listDelNode(list *l, node *n){
    if (n->prev)
        n->prev->next = n->next;
    else
        l->head = n->next;
    if (n->next)
        n->next->prev = n->prev;
    else
        l->tail = n->prev;
    if(l->free)
        l->free(n);
    free(n);
}

listIter *listGetIter(list *list,int direction){
    listIter *iter;
    iter=malloc(sizeof(*iter));
    if(iter==NULL)
        return NULL;
    if (LIST_START_HEAD==direction)
        iter->next=list->head;
    else
        iter->next=list->tail;
    iter->direction=direction;
    return iter;
}

node* listIterNext(listIter *iter){
    node *current=iter->next;
    if(current!=NULL){
        if(iter->direction==LIST_START_HEAD)
            iter->next=current->next;
        else
            iter->next=current->prev;
    }
    return current;
}