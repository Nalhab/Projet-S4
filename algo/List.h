#define _LIST_H_

struct list
{
    struct list *next;
    int data;
};

void list_init(struct list *list);

int list_is_empty(struct list *list);

size_t list_len(struct list *list);

void list_push_front(struct list *list, struct list *elm);

struct list *list_pop_front(struct list *list);

struct list *list_find(struct list *list, int value);

void list_insert(struct list *list, struct list *elm);
