// @file arraylist.h
// @author: Beka Modebadze
// @email: bexxmodd@gmail.com


/// Arraylist type
typedef struct arraylist {
    void** data; // array that will hold data
    unsigned int length; // total length of a list
    unsigned int capacity; // number of spots occupied
} arraylist;


/**
 * List constructor.
 * @param[out] arraylist pointer
 */
arraylist* new_arraylist();

/**
 * Allocates dynamic memory on the heap which is used to create list
 * and/or to expand current arraylist into copying in a new, larger one.
 * @param[in] arraylist pointer.
 * @param[in] size to be allocated for a data that list will hold initially.
 */
void arraylist_allocate(arraylist* list, unsigned int size);

/**
 * Append data to the end of the ArrayList.
 * @param[in] arraylist pointer where data needs to be appended.
 * @param[in] value which needs to be appended.
 */
void arraylist_append(arraylist* list, void* value);

/**
 * Add value on the given index and shifting the rest of list to the right.
 * @param[in] list to add value to.
 * @param[in] index where value will be added.
 * @param[in] value which will be added.
 */
void arraylist_insert(arraylist* list, unsigned int index, void* value);

/**
 * Add value on the top of the list (indexed 0).
 * This function uses other arraylist_insert function.
 * @param[in] list to add value to.
 * @param[in] value which will be added.
 */
void arraylist_push(arraylist* list, void* value);

/**
 * Get the data on a given index from a list. If index exceeds number
 * of values in the list, IndexOutofBound Exception will be thrown.
 * @param[in] list from where to retrieve data.
 * @param[in] index at which data needs to be retrieved.
 * @param[out] pointer to an value on the given index.
 */
void* arraylist_get(arraylist* list, unsigned int index);

/**
 * Replaces an given value to the ArrayList on a given index.
 * If index is out of bound, exception will be thrown.
 * @param[in] list to which value will be added.
 * @param[in] index at which to add an value.
 * @param[in] value that will be added to the list.
 */
void arraylist_replace(arraylist* list, unsigned int index, void* value);

/**
 * Remove the value on a given index. If index is out of bounds
 * Exception will the thrown. Or if there is no value on a given
 * index, Exception will be thrown.
 * @param[in] list from which to remove value.
 * @param[in] index at which to remove value.
 */
void* arraylist_removei(arraylist* list, unsigned int index);

void* arraylist_remove(arraylist* list, void* value);

/** Pop the last value in the list.
 * If the list is empty exception will be thrown.
 * @param[in] list to pop the value from.
 */
void* arraylist_pop(arraylist* list);