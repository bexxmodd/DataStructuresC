/**
 * @file smartlist.h
 * @author: Beka Modebadze
 * @email: bexxmodd@gmail.com
 * @date: 03/31/2021
 */


/// smartlist type
typedef struct smartlist {
    void** data; // array that will hold data
    unsigned int length; // total length of a list
    unsigned int capacity; // number of spots occupied
} smartlist;


/**
 * List constructor.
 * @param[out] smartlist pointer
 */
smartlist* new_smartlist();

/**
 * Allocates dynamic memory on the heap which is used to create list
 * and/or to expand current smartlist into copying in a new, larger one.
 * @param[in] smartlist pointer.
 * @param[in] size to be allocated for a data that list will hold initially.
 */
void smartlist_allocate(smartlist* list, unsigned int size);

/**
 * Dealocates space on dynamic memory when the number of used spaces 
 * is below 50% of the allocated space and more than initial capacity.
 * @param[in] list at which the dealocation will be performed.
 */
void smartlist_dealocate(smartlist* list);

/**
 * Append data to the end of the smartlist.
 * @param[in] smartlist pointer where data needs to be appended.
 * @param[in] value which needs to be appended.
 */
void smartlist_append(smartlist* list, const void* value);

/**
 * Add value on the given index and shifting the rest of list to the right.
 * @param[in] list to add value to.
 * @param[in] index where value will be added.
 * @param[in] value which will be added.
 */
void smartlist_insert(smartlist* list, unsigned int index, const void* value);

/**
 * Add value on the top of the list (indexed 0).
 * This function uses other smartlist_insert function.
 * @param[in] list to add value to.
 * @param[in] value which will be added.
 */
void smartlist_push(smartlist* list, const void* value);

/**
 * Get the data on a given index from a list. If index exceeds number
 * of values in the list, IndexOutofBound Exception will be thrown.
 * @param[in] list from where to retrieve data.
 * @param[in] index at which data needs to be retrieved.
 * @param[out] pointer to an value on the given index.
 */
void* smartlist_get(smartlist* list, unsigned int index);

/**
 * Replaces an given value to the smartlist on a given index.
 * If index is out of bound, exception will be thrown.
 * @param[in] list to which value will be added.
 * @param[in] index at which to add an value.
 * @param[in] value that will be added to the list.
 */
void smartlist_replace(smartlist* list, unsigned int index, const void* value);

/**
 * Remove the value on a given index. If index is out of bounds
 * Exception will the thrown. Or if there is no value on a given
 * index, Exception will be thrown.
 * @param[in] list from which to remove value.
 * @param[in] index at which to remove value.
 */
void* smartlist_removei(smartlist* list, unsigned int index);

void* smartlist_remove(smartlist* list, const void* value);

/** Pop the last value in the list.
 * If the list is empty exception will be thrown.
 * @param[in] list to pop the value from.
 */
void* smartlist_pop(smartlist* list);

void smartlist_sort(smartlist* list);

void smartlist_reverse(smartlist* list);

void smartlist_free(smartlist* list);

int __comparetor(const void * a, const void * b);