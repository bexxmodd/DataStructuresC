#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "arraylist.h"

// maximum capacity at arraylist construction
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
#define arraylist_memmove(arr, offset, length) \
            memmove((arr) + (offset), (arr), (length) * sizeof(arr))

///< creates the arraylist iterator
#define arraylist_iter(list, index, value) \
            for (index = 0, value = list->data[0]; index < list->size; value = list->data[++index])


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
        unsigned int new_cap = list->capacity;

		while (new_cap * 0.6 < size)
			new_cap *= 2;
        
        list->data = realloc(list->data, sizeof(void*) * new_cap);
        assert(list->data);
        list->capacity = new_cap;
    }
}

void arraylist_dealocate(arraylist* list)
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

void arraylist_append(arraylist* list, const void* value)
{
    arraylist_allocate(list, list->length);
    list->data[list->length++] = value;
}

void arraylist_insert(
    arraylist* list, unsigned int index, const void* value)
{
    if (index > list->length)
        INDEX_OUT_OF_BOUND(index);
    
    // check if current capacity will suffice & allocate if not
    arraylist_allocate(list, list->length + 1);

    // create extra spot for a new value by shifting array by 1
    arraylist_memmove(
        list->data + index, 1, list->length - index);
    list->data[index] = value;
    list->length++;
}

void arraylist_push(arraylist* list, const void* value)
{
    arraylist_insert(list, 0, value);
}

void* arraylist_get(arraylist* list, unsigned int index)
{
    if (index > list->length)
        INDEX_OUT_OF_BOUND(index);
    return list->data[index];
}

int arraylist_geti(arraylist* list, void* value)
{
    for (int i = 0; i < list->length; i++)
        if (list->data[i] == value)
            return i;
    return -1;
}

void arraylist_replace(
    arraylist* list, unsigned int index, const void* value)
{
    if (index > list->length)
        INDEX_OUT_OF_BOUND(index);
    list->data[index] = value;
}

void* arraylist_pop(arraylist* list)
{
    int last = list->length - 1;
    arraylist_dealocate(list);
    return arraylist_removei(list, last);
}

void* arraylist_removei(arraylist* list, unsigned int index)
{
    if (index > list->length)
        NULL_TYPE_ERROR();

    // set up the return value
    void* value = list->data[index];

    // shift arrayList to the left by one
    arraylist_memmove(
        list->data + index + 1, -1, list->length - index);
    list->length--;
    arraylist_dealocate(list);
    
    return value;
}

void* arraylist_remove(arraylist* list, const void* value)
{
    void* val;
    for (int i = 0; i < list->length; i++)
        if (list->data[i] == value)
            val = arraylist_removei(list, i);
    arraylist_dealocate(list);
    return val;
}

///< compares two data valus
int __comparator(const void * a, const void * b)
{
   return ( *(int*) a - *(int*) b );
}

void arraylist_sort(arraylist* list)
{
    qsort(list->data, list->length, sizeof(list->data[0]), &__comparator);
}

void arraylist_reverse(arraylist* list)
{
    void* tmp;
    register int low, high, len = list->length;

    for (low = 0, high = len - 1; low < high; low++, high--) {
        tmp = list->data[low];
        list->data[low] = list->data[high];
        list->data[high] = tmp;
    }
}

bool arraylist_contains(arraylist* list, void* value)
{
    for (int i = 0; i < list->length; i++)
        if (list->data[i] == value)
            return true;
    return false;
}

