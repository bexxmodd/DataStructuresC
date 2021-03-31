#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"


int main()
{
    int i;
    arraylist* list;
    list = new_arraylist();
    arraylist_append(list, 2);
    arraylist_append(list, 3);
    arraylist_append(list, 5);
    arraylist_append(list, 8);
    printf("Size of list: %d\n", list->length);
    printf("Capacity of list: %d\n", list->capacity);
    for (i = 0; i < list->length; i++)
        printf("%d, ", list->data[i]);
    printf("\n");

    /********* Test insert and push *********/
    arraylist_push(list, 10);
    arraylist_insert(list, 2, 13);

    printf("Size of list: %d\n", list->length);
    printf("Capacity of list: %d\n", list->capacity);
    for (i = 0; i < list->length; i++)
        printf("%d, ", list->data[i]);
    
    /********* Test get and geti *********/
    printf("get: Item on index %d is %d\n", 2, (int*) arraylist_get(list, 1));
    for (i = 0; i < list->length; i++)
        printf("%d, ", list->data[i]);
    printf("\n");

    printf("geti: Value %d has an index %d\n", 5, arraylist_geti(list, 5));
    for (i = 0; i < list->length; i++)
        printf("%d, ", list->data[i]);
    printf("\n");

    /********* Test replace *********/
    arraylist_replace(list, 1, 21);
    printf("repalce: Now, item at index %d is %d\n", 1, list->data[1]);
    for (i = 0; i < list->length; i++)
        printf("%d, ", list->data[i]);
    printf("\n");

    /********* Test remove, pop, and  *********/
    int r1 = arraylist_removei(list, 4);
    printf("removei: Removed item is %d, and the length of a list is %d\n", r1, list->length);
    for (i = 0; i < list->length; i++)
        printf("%d, ", list->data[i]);
    printf("\n");

    int r2 = arraylist_remove(list, 3);
    printf("remove: Removed item is %d, and the length of a list is %d\n", r2, list->length);
    for (i = 0; i < list->length; i++)
        printf("%d, ", list->data[i]);
    printf("\n");

    int r3 = arraylist_pop(list);
    printf("pop: poped item is %d, and the length of a list is %d\n", r3, list->length);
    for (i = 0; i < list->length; i++)
        printf("%d, ", list->data[i]);
    printf("\n");
    printf("Length: %d; and updated Cap: %d\n", list->length, list->capacity);

    /********* Test sort  *********/
    arraylist_insert(list, 1, 99);
    arraylist_sort(list);
    for (i = 0; i < list->length; i++)
        printf("%d, ", list->data[i]);
    printf("\n");

    printf("End\n");
    return 0;
}

