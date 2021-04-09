#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main()
{
    node *head = create_node(3);
    append_node(head, 5);
    append_node(head, 6);
    print_nodes(head);
    puts(" ");

    push_node(&head, 2);
    push_node(&head, 1);
    print_nodes(head);
    puts(" ");

    add_node(head, 13, 2);
    print_nodes(head);
    puts(" ");

    int x = pop_node(&head);
    printf("%d\n", x);
    print_nodes(head);

    x = rightpop_node(head);
    printf("%d\n", x);
    print_nodes(head);

    return 0;
}