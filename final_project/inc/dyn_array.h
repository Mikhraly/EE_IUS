#ifndef DYN_ARRAY_H
#define DYN_ARRAY_H

#include <stdlib.h>
#include <string.h>

typedef struct dyn_array{
    unsigned int count;
    unsigned int block_size;
    char *data;
} Dyn_array;

Dyn_array* dyn_array_create(unsigned int block_size);
void dyn_array_add(Dyn_array *da, void *element);
void* dyn_array_get(Dyn_array *da, unsigned int i);
void dyn_array_set(Dyn_array *da, unsigned int i, void *element);
void dyn_array_del(Dyn_array *da, unsigned int i);
void dyn_array_free(Dyn_array *da);

#endif