#include <stdio.h>

void sort_up(int* arr, int size);
void swap(int* a, int* b);

int main()
{
    int n;
    scanf("%d", &n);

    int arr[10] = {0};
    int arr_i = 0;

    for (int number = n % 10; n > 0; n /= 10, number = n % 10) {
        arr[arr_i++] = number;
    }

    sort_up(arr, arr_i);

    int result = 0;
    for (int i = arr_i - 1; i >= 0; i--) {
        result = result * 10 + arr[i];
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