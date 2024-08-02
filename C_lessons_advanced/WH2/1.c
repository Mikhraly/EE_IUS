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