#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

#define ERROR(n, f) ({printf("Line %d: %s >> Exception was thrown", n, f); \
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
    node *new_node = create_node(val);
    if (n == NULL)
        return new_node; //if list is empty new_node is head
    node *head = n;

    //< travers till the end of the list
    for (; n->next != NULL; n = n->next);
    n->next = new_node;
    return head;
}

node *push_node(node *n, void *val)
{
    node *new_node = create_node(val);
    new_node->next = n;
    return new_node;
}

node *remove_last_node(node *n)
{
    if (n == NULL)
        ERROR(__LINE__, __FUNCTION__);

    node *last_node;
    for (; n->next->next != NULL; n = n->next);
    last_node = n->next;
    free(n->next);
    n->next = NULL;
    return last_node;
}

void clear_node(node *n)
{
    for (; n != NULL; n = n->next)
        free(n);
}