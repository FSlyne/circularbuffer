#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cbuffer.h"

void lpush(struct cbuffer **st, struct cbuffer **en, char * value, int size)
{
    struct cbuffer *newnode;

    if (*st == NULL)
        {
        newnode = (struct cbuffer *)malloc(sizeof(struct cbuffer));
        newnode->size=size;
        int i; for (i=0; i<size; i++) (newnode->data)[i]= value[i];(newnode->data)[size]='\0';
        newnode->next = NULL;
        newnode->prev = NULL;
        *st=newnode; *en = newnode;
        return;
        }
 
    newnode = (struct cbuffer *)malloc(sizeof(struct cbuffer));
    newnode->size=size;
    int i; for (i=0; i<size; i++) (newnode->data)[i]= value[i];(newnode->data)[size]='\0';
    newnode->next = *st;
    (*st)->prev = newnode;
    *st = newnode;
    newnode->prev = NULL;
    return ;
 
}

void rpush(struct cbuffer **st, struct cbuffer **en,char *value, int size)
{
    struct cbuffer *newnode;
 
    if (*en == NULL)
        {
        newnode = (struct cbuffer *)malloc(sizeof(struct cbuffer));
        newnode->size=size;
        int i; for (i=0; i<size; i++) (newnode->data[i])= value[i];(newnode->data)[size]='\0';
        newnode->next = NULL;
        newnode->prev = NULL;
        *st=newnode; *en = newnode;
        return;
        }
 
    newnode = (struct cbuffer *)malloc(sizeof(struct cbuffer));
    newnode->size=size;
    int i; for (i=0; i<size; i++) (newnode->data[i])= value[i];(newnode->data)[size]='\0';
    newnode->prev = *en;
    (*en)->next = newnode;
    *en = newnode;
    newnode->next = NULL;
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

