/**
 * Header file of a SmartList module
 * 
 * @file smartlist.h
 * @author: Beka Modebadze
 * @email: bexxmodd@gmail.com
 * @date: 03/31/2021
 */


/// smartlist type
typedef struct smartlist {
    void            **data; // array that will hold data
    unsigned int    length; // total length of a list
    unsigned int    capacity; // number of spots occupied
} smartlist;


/**
 * List constructor.
 * @param[out] smartlist pointer
 */
smartlist *new_smartlist();

/**
 * Allocates dynamic memory on the heap which is used to create list
 * and/or to expand current smartlist into copying in a new, larger one.
 * @param[in] smartlist pointer.
 * @param[in] size to be allocated for a data that list will hold initially.
 */
void smartlist_allocate(smartlist *list, unsigned int size);

/**
 * Dealocates space on dynamic memory when the number of used spaces 
 * is below 50% of the allocated space and more than initial capacity.
 * @param[in] list at which the dealocation will be performed.
 */
void smartlist_dealocate(smartlist *list);

/**
 * Append data to the end of the smartlist.
 * @param[in] smartlist pointer where data needs to be appended.
 * @param[in] value which needs to be appended.
 */
void smartlist_append(smartlist *list, void *value);

/**
 * Add value on the given index and shifting the rest of list to the right.
 * @param[in] list to add value to.
 * @param[in] index where value will be added.
 * @param[in] value which will be added.
 */
void smartlist_insert(smartlist *list, unsigned int index, void *value);

/**
 * Add value on the top of the list (indexed 0).
 * This function uses other smartlist_insert function.
 * @param[in] list to add value to.
 * @param[in] value which will be added.
 */
void smartlist_push(smartlist *list, void *value);

/**
 * Get the data on a given index from a list. If index exceeds number
 * of values in the list, IndexOutofBound Exception will be thrown.
 * @param[in] list from where to retrieve data.
 * @param[in] index at which data needs to be retrieved.
 * @param[out] pointer to an value on the given index.
 */
void *smartlist_get(smartlist *list, unsigned int index);

/**
 * Replaces an given value to the smartlist on a given index.
 * If index is out of bound, exception will be thrown.
 * @param[in] list to which value will be added.
 * @param[in] index at which to add an value.
 * @param[in] value that will be added to the list.
 */
void smartlist_replace(smartlist *list, unsigned int index, void *value);

/**
 * Remove the value on a given index. If index is out of bounds
 * Exception will the thrown. Or if there is no value on a given
 * index, Exception will be thrown.
 * @param[in] list from which to remove value.
 * @param[in] index at which to remove value.
 */
void *smartlist_removei(smartlist *list, unsigned int index);

/**
 * Remove the from a smartlist if the value is present in the list
 * If the value is not found in the list -1 will be returned.
 * @param[in] list from which to remove value.
 * @param[in] value to remove from list.
 */
void *smartlist_remove(smartlist *list, void *value);

/** 
 * Pop the last value in the list.
 * If the list is empty exception will be thrown.
 * @param[in] list to pop the value from.
 */
void *smartlist_pop(smartlist *list);

/**
 * Sort a smartlist in ascending order.
 * This function uses C native qsort function.
 * @param[in] list that needs to be sorted.
 */
void smartlist_sort(smartlist *list);

/**
 * Reverse given list inplace.
 * @param[in] list to be reversed
 */
void smartlist_reverse(smartlist *list);

/**
 * Merge two smartlists.
 * Second list will be appended at the end of the first list.
 * @param[in] list1
 * @param[in] list2
 */
void smartlist_merge(smartlist *list1, smartlist *list2);

/**
 * Extract the slice from a given smartlist and returns as a new smartlist
 * Slice will be between starting index and ending index inclusive
 * @param[in] list
 * @param[in] starti ng index. If more than list length exception will be thrown.
 * @param[in] endi ing index. If more than list length,
                        slice'll go till the end of the list.
 *                      If less than starting index exception will be thrown.
 * @param[out] smartlist
 */
smartlist *smartlist_slice(smartlist *list, unsigned int starti, unsigned int endi);

/**
 * Set all the values in the  list to zero
 * @param[in] list
 */
void smartlist_clear(smartlist *list);

/**
 * Free the space which was allocated for the smartlist
 * @param[in] list
 */
void smartlist_delete(smartlist *list);