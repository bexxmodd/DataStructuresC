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
            printf("EXCEPTION %s : [%d] > Index %d out of bound!\n", __FUNCTION__, __LINE__, index);\
            exit(EXIT_FAILURE);\
        })

///< throws an Exception when trying to acces the NULL value
#define NULL_TYPE_ERROR() ({\
            printf("EXCEPTION %s : [%d] > Can't remove NULL value\n", __FUNCTION__, __LINE__);\
            exit(EXIT_FAILURE);\
        })

///< shifts memory based on the need of insert or remove functions
#define smartlist_memmove(arr, offset, length) \
            memmove((arr) + (offset), (arr), (length) * sizeof(arr))

///< creates the smartlist iterator
#define smartlist_iter(list, index, value) \
            for (index = 0, value = list->data[0]; index < list->size; value = list->data[++index])

///< compares two data valus
static int _comperator(const void *a, const void *b)
{
    // assert(reverse >= -1 && reverse <= 1);
    return -1 * ( *(int*) a - *(int*) b );
}

//***** SmartList Constructor *****//
smartlist *new_smartlist()
{
    smartlist *list = malloc(sizeof(smartlist));
    void *arr = calloc(sizeof(int), INITIAL_CAPACITY);
    list->data = arr;
    assert(list->data);
    list->length = 0;
    list->capacity = INITIAL_CAPACITY;
    return list;
}

void smartlist_allocate(smartlist *list, unsigned int size)
{
    if (size > list->capacity * 0.7) {
        unsigned int new_cap = list->capacity;
        // find new optimal size
		while (new_cap * 0.7 < size)
			new_cap *= 2;

        list->data = realloc(list->data, new_cap * sizeof(void*));
        assert(list->data);
        list->capacity = new_cap;
    }
}

void smartlist_dealocate(smartlist *list)
{
    unsigned int new_cap = list->capacity;
    if (list->length < list->capacity / 2 
        && list->capacity > INITIAL_CAPACITY)
        while (new_cap > list->capacity / 2) 
            new_cap /= 2; // shrink array size

    // new capacity shouldn't be less than INITIAL_CAPACITY
    new_cap = (new_cap > INITIAL_CAPACITY) ? new_cap : INITIAL_CAPACITY;
    list->data = realloc(list->data, sizeof(void*) * new_cap);
    assert(list->data);
    list->capacity = new_cap;
}

void smartlist_append(smartlist *list, void *value)
{
    smartlist_allocate(list, list->length + 1); // check if we need extra space
    list->data[list->length++] = value;
}

void smartlist_insert(
    smartlist *list, unsigned int index, void *value)
{
    if (index > list->length)
        INDEX_OUT_OF_BOUND(index);
    
    // check if current capacity will suffice; allocate if not
    smartlist_allocate(list, list->length + 1);

    // create extra spot for a new value by shifting array by 1
    smartlist_memmove(
        list->data + index, 1, list->length - index);
    list->data[index] = value;
    list->length++;
}

void smartlist_push(smartlist *list, void *value)
{
    smartlist_insert(list, 0, value);
}

void *smartlist_get(smartlist *list, unsigned int index)
{
    if (index > list->length)
        INDEX_OUT_OF_BOUND(index);
    return list->data[index];
}

int smartlist_geti(smartlist *list, void *value)
{
    register int i;
    for (i = 0; i < list->length; i++)
        if (list->data[i] == value)
            return i;
    return -1;
}

void smartlist_replace(
    smartlist* list, unsigned int index, void *value)
{
    if (index > list->length)
        INDEX_OUT_OF_BOUND(index);
    list->data[index] = value;
}

void *smartlist_pop(smartlist *list)
{
    int last = list->length - 1;
    smartlist_dealocate(list);
    return smartlist_removei(list, last);
}

void *smartlist_removei(smartlist *list, unsigned int index)
{
    if (index > list->length)
        NULL_TYPE_ERROR();

    // set up the return value
    void *val = list->data[index];

    // shift smartlist to the left by one
    smartlist_memmove(
        list->data + index + 1, -1, list->length - index);
    list->length--;
    smartlist_dealocate(list);
    return val;
}

void *smartlist_remove(smartlist *list, void *value)
{
    void *val;
    register int i;

    for (i = 0; i < list->length; i++)
        if (list->data[i] == value)
            val = smartlist_removei(list, i);
    smartlist_dealocate(list);
    return (val != NULL) ? val : NULL;
}

void smartlist_sort(smartlist* list)
{
    qsort(list->data, list->length, 
            sizeof(list->data[0]), _comperator);
}

void smartlist_reverse(smartlist *list)
{
    void *tmp;
    register int low, high;
    unsigned int len = list->length;

    for (low = 0, high = len - 1; low < high; low++, high--) {
        tmp = list->data[low];
        list->data[low] = list->data[high];
        list->data[high] = tmp;
    }
}

bool smartlist_contains(smartlist *list, void *value)
{
    register int i;
    for (i = 0; i < list->length; i++)
        if (list->data[i] == value)
            return true;
    return false;
}

void smartlist_merge(smartlist *list1, smartlist *list2)
{
    register int i;
    unsigned int new_length = list1->length + list2->length;
    smartlist_allocate(list1, new_length);
    
    for (i = 0; i < list2->length; i++)
        smartlist_append(list1, list2->data[i]);
}

smartlist *smartlist_slice(
    smartlist *list, unsigned int starti, unsigned int endi)
{
    if (starti >= list->length)
        INDEX_OUT_OF_BOUND(starti);
    if (endi < starti)
        INDEX_OUT_OF_BOUND(endi);
    
    smartlist* new_list = new_smartlist();
    endi = (list->length < endi) ? list->length : endi;

    for (; starti < endi; starti++)
        smartlist_append(new_list, list->data[starti]);
    return new_list;
}

void smartlist_clear(smartlist *list)
{
    unsigned int len = list->length;
    register int i;

    for (i = 0; i < len; i++)
        list->data[i] = 0;
}

void smartlist_delete(smartlist* list)
{
    free(list->data);
    free(list);
}

