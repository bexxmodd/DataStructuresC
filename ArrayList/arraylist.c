#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "arraylist.h"

// maximum capacity at arraylist construction
#define INITIAL_CAPACITY 4

// throws an Exception when index is out of bound
#define INDEX_OUT_OF_BOUND(index) \
            printf("EXCEPTION line [%d]: Index %d out of bound!", __LINE__, index); \
            exit(EXIT_FAILURE)

// throws an Exception when trying to acces the NULL value
#define NULL_TYPE_ERROR() \
            printf("EXCEPTION line [%d]: Can't remove NULL item", __LINE__); \
            exit(EXIT_FAILURE)

// shifts memory based on the need of insert or remove functions
#define arraylist_mem_shift(s, offset, length) \
            memmove((s) + (offset), (s), (length) * sizeof(s))

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

void arraylist_insert(
    arraylist* list, unsigned int index, void* item)
{
    if (index > list->length)
        INDEX_OUT_OF_BOUND(index);

    // check if current capacity will suffice & allocate if not
    arraylist_allocate(list, list->length + 1);

    // create extra spot for a new item by shifting array by 1
    arraylist_mem_shift(
        list->data + index, 1, list->length - index);
    list->length++;
}

void arraylist_push(arraylist* list, void* item)
{
    arraylist_insert(list, 0, item);
}

void* arraylist_get(arraylist* list, unsigned int index)
{
    if (index > list->length) {
        INDEX_OUT_OF_BOUND(index);
    }

    return list->data[index];
}

void arraylist_replace(
    arraylist* list, unsigned int index, void* item)
{
    if (index > list->length)
        INDEX_OUT_OF_BOUND(index);
    list->data[index] = item;
    list->length++;

    return 1;
}

void* arraylist_pop(arraylist* list)
{
    int last = list->length;
    void* item = arraylist_remove(list, --last);
    return item;
}

void* arraylist_remove(arraylist* list, unsigned int index)
{
    if (index > list->length)
        NULL_TYPE_ERROR();

    // set up the return value
    void* item = list->data[index];

    // shift arrayList to the left by one
    arraylist_mem_shift(
        list->data + index + 1, -1, list->length - index);
    list->length--;

    return item;
}