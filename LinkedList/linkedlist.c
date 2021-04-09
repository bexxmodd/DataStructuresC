#include <stdio.h>
#include <stdlib.h>
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

node *append_node(node *n, void *val)
{
    if (val == NULL)
        ERROR("can't append NULL value");

    node *new_node = create_node(val);
    if (n == NULL)
        return new_node; //if list is empty new_node is head
    node *head = n;

    //< travers till the end of the list
    for (; n->next != NULL; n = n->next);
    n->next = new_node;
    return head;
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
    puts("HERE");
    r = n->next->value;
    free(n->next);
    n->next = NULL;
    return r;
}

void print_nodes(node *n)
{
    for (; n != NULL; n = n->next)
        printf("%d -> ", n->value);
    printf("NULL\n");
}

void clear_nodes(node *n)
{
    for (; n != NULL; n = n->next)
        free(n);
}