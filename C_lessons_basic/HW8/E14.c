#include <stdio.h>

#define SIZE 10

int do_contain(int* arr, int size, int num);

int main()
{
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    int arr1[SIZE] = {0};
    int arr1_index = 0;
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (arr[i] == arr[j] && !do_contain(arr1, arr1_index + 1, arr[i])) {
                arr1[arr1_index++] = arr[i];
                break;
            }
        }
    }

    for (int i = 0; i < arr1_index; i++) {
        printf("%d ", arr1[i]);
    }

    return 0;
}

int do_contain(int* arr, int size, int num)
{
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return 1;
        }
    }
    return 0;
}