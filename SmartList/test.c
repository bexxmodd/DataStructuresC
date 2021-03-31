#include <stdio.h>
#include <stdlib.h>
#include "smartlist.h"


int main()
{
    int i;
    smartlist* list;

    /********* Test constructor and append *********/
    list = new_smartlist();
    smartlist_append(list, 2);
    smartlist_append(list, 3);
    smartlist_append(list, 5);
    smartlist_append(list, 8);
    printf("Size of list: %d\n", list->length);
    printf("Capacity of list: %d\n", list->capacity);
    for (i = 0; i < list->length; i++)
        printf("%d, ", list->data[i]);
    printf("\n");

    /********* Test insert and push *********/
    smartlist_push(list, 10);
    smartlist_push(list, 11);
    smartlist_insert(list, 2, 13);
    smartlist_insert(list, 3, 53);

    printf("Size of list: %d\n", list->length);
    printf("Capacity of list: %d\n", list->capacity);
    for (i = 0; i < list->length; i++)
        printf("%d, ", list->data[i]);
    
    /********* Test get and geti *********/
    printf("get: Item on index %d is %d\n", 2, (int*) smartlist_get(list, 1));
    for (i = 0; i < list->length; i++)
        printf("%d, ", list->data[i]);
    printf("\n");

    printf("geti: Value %d has an index %d\n", 5, smartlist_geti(list, 5));
    for (i = 0; i < list->length; i++)
        printf("%d, ", list->data[i]);
    printf("\n");

    /********* Test replace *********/
    smartlist_replace(list, 1, 21);
    printf("repalce: Now, item at index %d is %d\n", 1, list->data[1]);
    for (i = 0; i < list->length; i++)
        printf("%d, ", list->data[i]);
    printf("\n");

    /********* Test remove, removei, and pop *********/
    int r1 = smartlist_removei(list, 4);
    printf("removei: Removed item is %d, and the length of a list is %d\n", r1, list->length);
    for (i = 0; i < list->length; i++)
        printf("%d, ", list->data[i]);
    printf("\n");

    int r2 = smartlist_remove(list, 3);
    printf("remove: Removed item is %d, and the length of a list is %d\n", r2, list->length);
    for (i = 0; i < list->length; i++)
        printf("%d, ", list->data[i]);
    printf("\n");

    int r3 = smartlist_pop(list);
    printf("pop: poped item is %d, and the length of a list is %d\n", r3, list->length);
    for (i = 0; i < list->length; i++)
        printf("%d, ", list->data[i]);
    printf("\n");
    printf("Length: %d; and updated Cap: %d\n", list->length, list->capacity);

    /********* Test sort *********/
    smartlist_insert(list, 1, 99);
    puts(" Sorting...");
    smartlist_sort(list);
    for (i = 0; i < list->length; i++)
        printf("%d, ", list->data[i]);
    printf("\n\n");

    /********* Test merge *********/
    smartlist* list2 = new_smartlist();
    smartlist_append(list2, 313);
    smartlist_append(list2, 214);
    smartlist_append(list2, 218);
    smartlist_append(list2, 511);

    smartlist_merge(list, list2);
    puts(" After merging two smartlists");
    for (i = 0; i < list->length; i++)
        printf("%d, ", list->data[i]);
    printf("\n\n");

    /********* Test slice *********/
    smartlist* list3 = new_smartlist();
    list3 = smartlist_slice(list, 2, 5);
    puts(" After getting a slice of smartlist");
    for (i = 0; i < list3->length; i++)
        printf("%d, ", list3->data[i]);
    printf("\n\n");

    printf("\t    END\n");
    return 0;
}

