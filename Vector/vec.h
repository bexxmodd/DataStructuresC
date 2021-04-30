#include <stdlib.h>

#ifndef VEC_H
#define VEC_H

/**
  * Vec - a dinamically growable array of any type.
  */

/**
  * The Vect struct is a "thik pointer".
  *
  * Usrs of vc should not acces these members directly
  * instead, use the operations exposed in the functions below.
  */
typedef struct Vec {
        const size_t item_size; /* size of an item in bytes */
        size_t length;          /* number of items in Vec */
        size_t capacity;        /* number of items buffer can store */
        void *buffer;           /* heap memory storing items */
} Vec;

/* Constructor / Destructor */

Vec vec_value(size_t capacity, size_t item_size);

void vec_drop(vec *self);


/* Accessors */

size_t vec_length(const vec *self);

const void *vec_item(const vec *self);


