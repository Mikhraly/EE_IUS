#include <stdio.h>
#include <stdint.h>

#define SIZE 10

void swap(int* a, int* b);

int main()
{
    int32_t arr[SIZE];
    for (int32_t i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (arr[i] % 10 > arr[j] % 10) {
                swap(&arr[i], &arr[j]);
            }
        }
    }

    for (int32_t i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}