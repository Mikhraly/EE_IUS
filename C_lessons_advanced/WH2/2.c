#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct list {
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

void * findMaxBlock(list *head);
size_t totalMemoryUsage(list *head);


int main(int argc, char *argv)
{
    return 0;
}


void * findMaxBlock(list *head) {
    if (head == NULL)
        return 0;

    void *max_block = head->address;
    size_t max_size = head->size;
    for (list *ptr = head; ptr; ptr = ptr->next) {
        if (ptr->size > max_size) {
            max_size = ptr->size;
            max_block = ptr->address;
        }
    }

    return max_block;
}

size_t totalMemoryUsage(list *head) {
    if (head == NULL)
        return 0;

    size_t size = 0;
    for (list *ptr = head; ptr; ptr = ptr->next) {
        size += ptr->size;
    }

    return size;
}