#include "dyn_array.h"

Dyn_array* dyn_array_create(unsigned int block_size) {
    Dyn_array *da = (Dyn_array*)malloc(sizeof(Dyn_array));
    da->count = 0;
    da->block_size = block_size;
    da->data = NULL;
    return da;
}

void dyn_array_add(Dyn_array *da, void *element) {
    da->count++;
    da->data = (char*)realloc(da->data, da->count * da->block_size);
    memcpy(&da->data[(da->count-1) * da->block_size], element, da->block_size);
}

void* dyn_array_get(Dyn_array *da, unsigned int i) {
    return &da->data[i * da->block_size];
}

void dyn_array_set(Dyn_array *da, unsigned int i, void *element) {
    if (i < 0 || i >= da->count)
        return;

    memcpy(&da->data[i * da->block_size], element, da->block_size);
}

void dyn_array_del(Dyn_array *da, unsigned int i) {
    if (i < 0 || i >= da->count)
        return;

    for (; i < da->count - 1; i++) {
        dyn_array_set(da, i, dyn_array_get(da, i + 1));
        da->count--;
        da->data = (char*)realloc(da->data, da->block_size * da->count);
    }
}

void dyn_array_free(Dyn_array *da) {
    if (da != NULL) {
        if (da->data != NULL) {
            free(da->data);
        }
        free(da);
    }
}