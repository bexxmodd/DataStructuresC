#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vec.h>

static void _ensure_capacity(vec *self, size_t n);

Vec vec_value(size_t capacity, size_t item_size)
{
        Vec vec = {
                item_size,
                0,
                capacity,
                calloc(capacity, item_size)
        };
        return vec;
}

static void _ensure_capacity(Vec *self, size_t n)
{
        if (n > self->capacity) {
                size_t new_capacity = n * 2;
                self->buffer = realloc(self->buffer, new_capacity * self->item_size);
                self->capacity = new_capacity;
        }
}

size_t vec_length(const Vec *self)
{
        return self->length;
}

const void *vec_items(const Vec *self)
{
        return self->buffer;


void vec_drop(Vec *self)
{
        free(self->buffer);
        self->buffer = NULL;
        self->capacity = 0;
        self->length = 0;
}
