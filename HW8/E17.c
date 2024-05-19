#include <stdio.h>

#define SIZE 10

int num_quantity(int* arr, int size, int num);

int main()
{
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    int arr1[SIZE] = {0};
    int arr1_index = 0;
    for (int i = 0, count = 0; i < SIZE; i++, count = 0) {
        count = num_quantity(arr, SIZE, arr[i]);
        if (count == 1) {
            arr1[arr1_index++] = arr[i];
        }
    }

    for (int i = 0; i < arr1_index; i++) {
        printf("%d ", arr1[i]);
    }
    return 0;
}

int num_quantity(int* arr, int size, int num)
{
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            count++;
        }
    }
    return count;
}