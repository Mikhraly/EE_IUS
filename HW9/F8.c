#include <stdio.h>

#define SIZE 1000

void sort_up(int* arr, int size);
void swap(int* a, int* b);

int main() {
    int arr[SIZE] = {0};
    int arr_len = 0;

    scanf("%d", &arr[arr_len]);
    while (arr[arr_len] != 0) {
        scanf("%d", &arr[++arr_len]);
    }

    sort_up(arr, arr_len);

    int result;
    for (int i = 0; i < arr_len; i++) {
        if (arr[i+1] - arr[i] > 1) {
            result = arr[i] + 1;
            break;
        }
    }

    printf("%d", result);
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

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}