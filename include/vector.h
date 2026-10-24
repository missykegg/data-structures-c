#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

typedef struct {
    void **items;
    size_t capacity;
    size_t size;
} Vector;

Vector *vector_create(size_t initial_capacity);
int vector_push_back(Vector *vec, void *item);
void *vector_get(Vector *vec, size_t index);
void *vector_pop_back(Vector *vec);
void vector_free(Vector *vec);

#endif
