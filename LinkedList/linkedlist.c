#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist.h"

#define ERROR(s) ({printf("ERROR at Line %d: %s() =>> %s\n", __LINE__, __FUNCTION__, s); \
                    exit(EXIT_FAILURE);})

node *create_node(void *val)
{
    node *new_node = (node*) malloc(sizeof(node));
    new_node->value = val;
    new_node->next = NULL;
    return new_node;
}

node *create_linkedlist(void **arr, unsigned int size)
{
    if (arr == NULL)
        ERROR("can't convert empty array to a linked list");
    node *head = create_node((void*) arr[0]);
    int i;
    for (i = 1; i < size; i++)
        append_node(head, (void*) arr[0]);
    return head;
}

node *append_node(node *n, void *val)
{
    if (val == NULL)
        ERROR("can't append NULL value");

    if (n == NULL) {
        ERROR("Please create a head node first");
    }

    node *new_node = create_node(val);

    //< travers till the end of the list
    for (; n->next != NULL; n = n->next);
    n->next = new_node;
    return n;
}

node *push_node(node **n, void *val)
{
    if (val == NULL)
        ERROR("can't push NULL value");
    node *new_head = create_node(val);
    new_head->next = *n;
    *n = new_head;
    return *n;
}

int add_node(node *n, void *val, unsigned int index)
{
    int i;
    node *new_node = create_node(val);
    if (index == 0)
        push_node(&n, val);

    for (i = 0; i < index - 1; i++, n = n->next);
    node *hold = n->next->next;
    n->next = new_node;
    n->next->next = hold;
    return 0;
}

void *pop_node(node **n)
{
    if (n == NULL)
        ERROR("can't pop from the empty list");
    void *r;
    node *new_head;
    r = (*n)->value; //setup the return value
    new_head = (*n)->next; //setup next node as a head
    free(*n);
    *n = new_head;
    return r;
}

void *rightpop_node(node *n)
{
    if (n == NULL)
        ERROR("can't pop from the empty list");
    void *r;
    for (; n->next->next != NULL; n = n->next);
    r = n->next->value;
    free(n->next);
    n->next = NULL;
    return r;
}

void *removei_node(node **n, unsigned int index)
{
    void *r;
    if (index == 0)
        return pop_node(n);

    node *tmp = *n;
    int i;
    for (i = 0; i < index-1 && tmp->next != NULL; tmp = tmp->next, i++);
    if (tmp == NULL || tmp->next == NULL)
        return NULL;
    r = tmp->next->value;
    node *new_next = tmp->next->next;
    free(tmp->next);
    tmp->next = new_next;
    return r;
}

void *remove_node(node **n, void *val)
{
    int i;
    node *tmp = *n;
    for (i = 0; tmp != NULL; tmp = tmp->next, i++)
        if (tmp->value == val)
            return removei_node(n, i);
    return NULL;
}

void *get_node(node *n, unsigned int index)
{
    if (n == NULL)
        ERROR("empty list was provided");
    
    int i;
    for (i = 0; i != index && n != NULL; i++, n = n->next);
    if (n == NULL)
        return NULL;
    return n->value;
}

void print_nodes(node *n)
{
    for (; n != NULL; n = n->next)
        printf("%d -> ", n->value);
    printf("NULL\n");
}

bool contains_node(node *n, void *val)
{
    for (; n != NULL; n = n->next)
        if (n->value == val)
            return true;
    return false;
}

void clear_nodes(node **n)
{
    node *cur = *n;
    node *next;
    while (cur != NULL) {
        next = cur->next;
        free(cur);
        cur = next;
    }
    *n = NULL;
}