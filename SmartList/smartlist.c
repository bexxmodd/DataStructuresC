#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "smartlist.h"

// maximum capacity at smartlist construction
#define INITIAL_CAPACITY 4

///< throws an Exception when index is out of bound
#define INDEX_OUT_OF_BOUND(index) ({\
            printf("EXCEPTION line [%d]: Index %d out of bound!\n", __LINE__, index);\
            exit(EXIT_FAILURE);\
        })

///< throws an Exception when trying to acces the NULL value
#define NULL_TYPE_ERROR() ({\
            printf("EXCEPTION line [%d]: Can't remove NULL value\n", __LINE__);\
            exit(EXIT_FAILURE);\
        })

///< shifts memory based on the need of insert or remove functions
#define smartlist_memmove(arr, offset, length) \
            memmove((arr) + (offset), (arr), (length) * sizeof(arr))

///< creates the smartlist iterator
#define smartlist_iter(list, index, value) \
            for (index = 0, value = list->data[0]; index < list->size; value = list->data[++index])


//***** Constructor *****//
smartlist* new_smartlist()
{
    smartlist* list = malloc(sizeof(smartlist));
    void* arr = calloc(sizeof(int), INITIAL_CAPACITY);
    list->data = arr;
    assert(list->data);

    list->length = 0;
    list->capacity = INITIAL_CAPACITY;

    return list;
}

void smartlist_allocate(smartlist* list, unsigned int size)
{
    if (size > list->capacity * 0.6) {
        unsigned int new_cap = list->capacity;

		while (new_cap * 0.6 < size)
			new_cap *= 2;
        
        list->data = realloc(list->data, sizeof(void*) * new_cap);
        assert(list->data);
        list->capacity = new_cap;
    }
}

void smartlist_dealocate(smartlist* list)
{
    unsigned int new_cap = list->capacity;
    if (list->length < list->capacity / 2 
        && list->capacity > INITIAL_CAPACITY)
        while (new_cap > list->capacity / 2)
            new_cap /= 2;

    // new capacity should not be less than INITIAL CAPACITY
    new_cap = (new_cap > INITIAL_CAPACITY) ? new_cap : INITIAL_CAPACITY;
    list->data = realloc(list->data, sizeof(void*) * new_cap);
    assert(list->data);
    list->capacity = new_cap;
}

void smartlist_append(smartlist* list, const void* value)
{
    smartlist_allocate(list, list->length);
    list->data[list->length++] = value;
}

void smartlist_insert(
    smartlist* list, unsigned int index, const void* value)
{
    if (index > list->length)
        INDEX_OUT_OF_BOUND(index);
    
    // check if current capacity will suffice & allocate if not
    smartlist_allocate(list, list->length + 1);

    // create extra spot for a new value by shifting array by 1
    smartlist_memmove(
        list->data + index, 1, list->length - index);
    list->data[index] = value;
    list->length++;
}

void smartlist_push(smartlist* list, const void* value)
{
    smartlist_insert(list, 0, value);
}

void* smartlist_get(smartlist* list, unsigned int index)
{
    if (index > list->length)
        INDEX_OUT_OF_BOUND(index);
    return list->data[index];
}

int smartlist_geti(smartlist* list, void* value)
{
    for (int i = 0; i < list->length; i++)
        if (list->data[i] == value)
            return i;
    return -1;
}

void smartlist_replace(
    smartlist* list, unsigned int index, const void* value)
{
    if (index > list->length)
        INDEX_OUT_OF_BOUND(index);
    list->data[index] = value;
}

void* smartlist_pop(smartlist* list)
{
    int last = list->length - 1;
    smartlist_dealocate(list);
    return smartlist_removei(list, last);
}

void* smartlist_removei(smartlist* list, unsigned int index)
{
    if (index > list->length)
        NULL_TYPE_ERROR();

    // set up the return value
    void* value = list->data[index];

    // shift smartlist to the left by one
    smartlist_memmove(
        list->data + index + 1, -1, list->length - index);
    list->length--;
    smartlist_dealocate(list);
    
    return value;
}

void* smartlist_remove(smartlist* list, const void* value)
{
    void* val;
    for (int i = 0; i < list->length; i++)
        if (list->data[i] == value)
            val = smartlist_removei(list, i);
    smartlist_dealocate(list);
    return val;
}

///< compares two data valus
int __comperator(const void * a, const void * b)
{
    return ( *(int*) a - *(int*) b );
}

void smartlist_sort(smartlist* list)
{
    qsort(list->data, list->length, sizeof(list->data[0]), &__comperator);
}

void smartlist_reverse(smartlist* list)
{
    void* tmp;
    register int low, high, len = list->length;

    for (low = 0, high = len - 1; low < high; low++, high--) {
        tmp = list->data[low];
        list->data[low] = list->data[high];
        list->data[high] = tmp;
    }
}

bool smartlist_contains(smartlist* list, void* value)
{
    for (int i = 0; i < list->length; i++)
        if (list->data[i] == value)
            return true;
    return false;
}

void smartlist_free(smartlist* list)
{
    free(list->data);
    free(list);
}

