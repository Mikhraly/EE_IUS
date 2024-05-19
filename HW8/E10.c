#include <stdio.h>
#include <stdint.h>

#define SIZE 12

void shift_arr_right(int* arr, int size, int steps);
void reverse_arr(int* arr, int size);
void swap(int* a, int* b);

int main()
{
    int32_t arr[SIZE];
    for (int32_t i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    shift_arr_right(arr, SIZE, 4);

    for (int32_t i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void shift_arr_right(int* arr, int size, int steps)
{
    for (int i = 0; i < steps; i++) {
        for (int i = 0; i < size - 1; i++) {
            swap(&arr[i], &arr[size - 1]);
        }
    }
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