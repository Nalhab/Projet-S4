#include <stdlib.h>
#include "list.h"
#include <stdio.h>
void list_init(struct list *list)
{
    list->next = NULL;
}

int list_is_empty(struct list *list)
{
    return list->next == NULL;
}

size_t list_len(struct list *list)
{
    size_t i = 0;
    while(list->next != NULL)
    {
        list = list->next;
        i++;
    }
    return i;
}

void list_push_front(struct list *list, struct list *elm)
{
    struct list *l = list->next;
    list->next = elm;
    while(elm->next !=  NULL)
    {
        elm = elm->next;
    }
    elm->next = l;
}

struct list *list_pop_front(struct list *list)
{
    list->next = NULL;
    return list;
}

struct list *list_find(struct list *list, int value)
{
    struct list *tmp = list;
    while(tmp->data != value && tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    if(tmp->data == value)
        return tmp;
    else return NULL;
}

void list_insert(struct list *list, struct list *elm)
{
    struct list *tmp = list;
    while(tmp->next != NULL && tmp->next->data < elm->data)
    {
        tmp = tmp->next;
    }
    struct list *nextv = tmp->next;
    tmp->next = elm;
    elm->next = nextv;
}
