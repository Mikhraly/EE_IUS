#include <stdio.h>
#include <stdint.h>

#define SIZE 10

void reverse_arr(int* arr, int size);
void swap(int* a, int* b);

int main()
{
    int32_t arr[SIZE];
    for (int32_t i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    // reverse_arr(arr, SIZE / 2);
    // reverse_arr(arr + SIZE / 2, SIZE / 2);

    int parts = 2;
    for (int i = 0; i < parts; i++) {
        reverse_arr(arr + i * SIZE / parts, SIZE / parts);
    }

    for (int32_t i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void reverse_arr(int* arr, int size)
{
    int a_index = 0;
    int b_index = size - 1;

    while (a_index < b_index) {
        swap(&arr[a_index], &arr[b_index]);
        a_index++;
        b_index--;
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}