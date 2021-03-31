#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

int main()
{
    arraylist* list;
    list = new_arraylist();
    arraylist_append(list, 2);
    arraylist_append(list, 3);
    arraylist_append(list, 5);

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

// maximum capacity at arraylist construction
#define INITIAL_CAPACITY 4

// throws an Exception when index is out of bound
#define INDEX_OUT_OF_BOUND(index) \
            printf("EXCEPTION line [%d]: Index %d out of bound!", __LINE__, index); \
            exit(EXIT_FAILURE)

// throws an Exception when trying to acces the NULL value
#define NULL_TYPE_ERROR() \
            printf("EXCEPTION line [%d]: Can't remove NULL item", __LINE__, index); \
            exit(EXIT_FAILURE)

// shifts memory based on the need of insert or remove functions
#define arraylist_mem_shift(s, offset, length) \
            memmove(s) + (offset), (s), (length) * sizeof(s)

// creates the arraylist iterator
#define arraylist_iter(list, index, item) \
            for (index = 0, item = list->data[0]; index < list->size; item = list->data[++index])

//***** Constructor *****//
arraylist* new_arraylist()
{
    arraylist* list = malloc(sizeof(arraylist));
    void* arr = calloc(sizeof(int), INITIAL_CAPACITY);
    list->data = arr;
    assert(list->data);

    list->length = 0;
    list->capacity = INITIAL_CAPACITY;

    return list;
}

void arraylist_allocate(arraylist* list, unsigned int size)
{
    if (size > list->capacity * 0.6) {
        unsigned int new_capacity = list->capacity;
		while (new_capacity * 0.6 < size)
			new_capacity *= 2;
        
        list->data = realloc(list->data, sizeof(void*) * new_capacity);
        assert(list->data);
        list->capacity = new_capacity;
    }
}

void arraylist_append(arraylist* list, void* item)
{
    arraylist_allocate(list, list->length);
    list->data[list->length++] = item;
}

void* arraylist_get(arraylist* list, unsigned int index)
{
    if (index < 0 || index > list->length) {
        INDEX_OUT_OF_BOUND(index);
    }

    return list->data[index];
}

void arraylist_add(
    arraylist* list, unsigned int index, void* item)
{
    if (index < 0 || index > list->length)
        INDEX_OUT_OF_BOUND(index);
    list->data[index] = item;

    return 1;
}

void* arraylist_remove(arraylist* list, unsigned int index)
{
    if (index < 0 || index > list->length)
        NULL_TYPE_ERROR();
}