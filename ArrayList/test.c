#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"


int main()
{
    arraylist* list;
    list = new_arraylist();
    arraylist_append(list, 2);
    arraylist_append(list, 3);
    arraylist_append(list, 5);
    arraylist_add(list, 1, 12);

    printf("Size of list: %d\n", list->length);
    printf("Capacity of list: %d\n", list->capacity);
    for (int i = 0; i < 3; i++)
        printf("%d, ", list->data[i]);
    printf("\n");
    printf("Item on index %d is %d\n", 1, (int*) arraylist_get(list, 1));
    arraylist_get(list, 4);
    printf("Here\n");
    return 0;
}

