#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cbuffer.h"

void insert(struct cbuffer **st, struct cbuffer **en, char * value, int size, int key)
{
    struct cbuffer *newnode;
    struct cbuffer *idx, *tmp;

    newnode = (struct cbuffer *)malloc(sizeof(struct cbuffer));
    newnode->size=size;
    newnode->key=key;
    
    int i; for (i=0; i<size; i++)
        (newnode->data)[i]= value[i];
    (newnode->data)[size]='\0';

    idx=*st;
    while (idx) {
        if (key >= idx->key)  // --> 7,6,5,4,3,2 --> 
            break;
        idx = idx->next;
        }
    if (*st == NULL && *en == NULL) { // zero nodes in list, insert new node
        newnode->next=NULL;
        newnode->prev=NULL;
        *st=newnode;
        *en=newnode;
    } else if (idx == *st) { // idx pointing to start, insert before this at beginning
        newnode->next=*st;
        newnode->prev=NULL;
        (*st)->prev = newnode;
        *st = newnode;
    } else if (idx == NULL) { // idx has reached end, insert at end
        newnode->next=NULL;
        newnode->prev=*en;
        (*en)->next=newnode;
        *en = newnode;
    } else { // idx is in between *st and *en, no change to st nor en
        tmp=idx->prev; // this should be safe
        tmp->next=newnode;
        newnode->prev=tmp;
        newnode->next=idx;
        idx->prev=newnode;
    }
    return;
}

void lpush(struct cbuffer **st, struct cbuffer **en, char * value, int size)
{
    struct cbuffer *newnode;

    newnode = (struct cbuffer *)malloc(sizeof(struct cbuffer));
    newnode->size=size;
    int i; for (i=0; i<size; i++)
        (newnode->data)[i]= value[i];
    (newnode->data)[size]='\0';
    newnode->prev = NULL;
    newnode->next = *st; // *st could be NULL, if the linked list is empty
    if (*st == NULL) {
        *en = newnode;
    } else {
        (*st)->prev = newnode;
    }
    *st = newnode;
    return ;
 
}

void rpush(struct cbuffer **st, struct cbuffer **en,char *value, int size)
{
    struct cbuffer *newnode;
 
    newnode = (struct cbuffer *)malloc(sizeof(struct cbuffer));
    newnode->size=size;
    int i; for (i=0; i<size; i++)
        (newnode->data[i])= value[i];
    (newnode->data)[size]='\0';
    newnode->prev = *en; // *en could be NULL, if the linked list is empty
    newnode->next = NULL;
    if (*en == NULL) {
        *st=newnode;
    } else {
        (*en)->next = newnode;
    }
    *en = newnode;
    return ;
 
}
 
void rpop(struct cbuffer **st, struct cbuffer **en,  char *value, int *size)
{
    struct cbuffer *top;

    value[0]='\0'; *size=0;
 
    if (*st == NULL && *en == NULL)
        {
        printf("The stack is empty!\n");
        return ;
        }

    top = *en;       
    *size=top->size;
    int i; for (i=0; i<*size; i++) value[i]=(top->data)[i];
    if (*st == *en) {
        *st = NULL;
        *en = NULL;
        free(top);
        return;
    }

    *en = (*en)->prev;
    (*en)->next=NULL;
    free(top);
    return ;
 
}

void lpop(struct cbuffer **st, struct cbuffer **en, char *value, int *size)
{
    struct cbuffer *top;

    value[0]='\0'; *size=0;
 
    if (*st == NULL && *en == NULL)
        {
        printf("The stack is empty!\n");
        return ;
        }

    top = *st;       
    *size=top->size;
    int i; for (i=0; i<*size; i++) value[i]=(top->data)[i];
    if (*st == *en) {
        *st = NULL;
        *en = NULL;
        free(top);
        return;
    }
    

    *st = (*st)->next;
    (*st)->prev=NULL;
    free(top);
    return ;
 
}

void clear(struct cbuffer **st, struct cbuffer **en)
{
    struct cbuffer *top;
    
    while (!(*st == NULL && *en == NULL)) {   
        top = *st;       
        if (*st == *en) {
            *st = NULL;
            *en = NULL;
            free(top);
        } else {
            *st = (*st)->next;
            (*st)->prev=NULL;
            free(top);       
        }
    }
}

void printstack(struct cbuffer *st)
{
    if (st == NULL)
        {
        printf("The stack is empty!\n");
        return;
        }
 
    do
        {
        printf("%s ", st->data);
        st = st->next;
        }
    while (st);
    printf("\n");
}

