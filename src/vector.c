#include "vector.h"
#include <stdlib.h>

Vector *vector_create(size_t initial_capacity) {
    Vector *vec = malloc(sizeof(Vector));
    if (!vec) return NULL;
    vec->capacity = initial_capacity ? initial_capacity : 8;
    vec->size = 0;
    vec->items = malloc(sizeof(void *) * vec->capacity);
    if (!vec->items) {
        free(vec);
        return NULL;
    }
    return vec;
}

int vector_push_back(Vector *vec, void *item) {
    if (!vec) return 0;
    if (vec->size >= vec->capacity) {
        size_t new_cap = vec->capacity * 2;
        void **new_items = realloc(vec->items, sizeof(void *) * new_cap);
        if (!new_items) return 0;
        vec->items = new_items;
        vec->capacity = new_cap;
    }
    vec->items[vec->size++] = item;
    return 1;
}

void *vector_get(Vector *vec, size_t index) {
    if (!vec || index >= vec->size) return NULL;
    return vec->items[index];
}

void *vector_pop_back(Vector *vec) {
    if (!vec || vec->size == 0) return NULL;
    return vec->items[--vec->size];
}

void vector_free(Vector *vec) {
    if (vec) {
        free(vec->items);
        free(vec);
    }
}
