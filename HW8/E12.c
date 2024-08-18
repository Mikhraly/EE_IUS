#include <stdio.h>
#include <stdint.h>

#define SIZE 10

void sort_up(int* arr, int size);
void sort_down(int* arr, int size);
void swap(int* a, int* b);

int main()
{
    int32_t arr[SIZE];
    for (int32_t i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    sort_up(arr, SIZE / 2);
    sort_down(arr + SIZE / 2, SIZE / 2);

    for (int32_t i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void sort_up(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void sort_down(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}