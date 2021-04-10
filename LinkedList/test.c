#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main()
{
    // TODO: -----------------------------
    /* Check each function one by one 
        to see which has a memmory leak */
    //------------------------------------

    node *head = create_node(1);
    append_node(head, 3);
    append_node(head, 5);
    append_node(head, 6);
    append_node(head, 8);
    print_nodes(head);
    // int nums[] = {542, 123, 634, 231, 234, 131, 973};
    // node *llist = create_linkedlist(nums, 7);
    // print_nodes(llist);
    reverse_nodes(&head);
    print_nodes(head);
    clear_nodes(&head);

    // push_node(&head, 2);
    // push_node(&head, 1);
    // print_nodes(head);
    // puts(" ");

    // add_node(head, 13, 2);
    // print_nodes(head);
    // puts(" ");

    // int x = pop_node(&head);
    // printf("%d\n", x);
    // puts(" ");

    // int g = get_node(head, 1);
    // printf("%d\n", g);

    // append_node(head, 15);
    // append_node(head, 26);
    // append_node(head, 35);
    // append_node(head, 46);
    // print_nodes(head);

    // removei_node(&head, 3);
    // print_nodes(head);
    // remove_node(&head, 35);
    // print_nodes(head);
    // clear_nodes(&head);

    return 0;
}