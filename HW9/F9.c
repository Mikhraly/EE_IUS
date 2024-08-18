#include <stdio.h>

#define SIZE 10

void swap_negmax_last(int size, int a[]);

int main() {
    int arr[SIZE] = {1, -2, -3, -4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    swap_negmax_last(SIZE, arr);

    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void swap_negmax_last(int size, int a[])
{
    int* negmax = NULL;
    for (int i = 0; i < size; i++) {
        if (a[i] < 0) {
            if (negmax == NULL) {
                negmax = &a[i];
            } else if (a[i] > *negmax) {
                negmax = &a[i];
            }
        }
    }

    if (negmax != NULL) {
        int temp = *negmax;
        *negmax = a[size - 1];
        a[size - 1] = temp;
    }
}