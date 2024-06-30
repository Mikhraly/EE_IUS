#include <stdio.h>

#define SIZE 10

int main()
{
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    int arr_pos[SIZE] = {0};
    int arr_neg[SIZE] = {0};
    int arr_pos_i = 0;
    int arr_neg_i = 0;

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] > 0) {
            arr_pos[arr_pos_i++] = arr[i];
        } else if (arr[i] < 0) {
            arr_neg[arr_neg_i++] = arr[i];
        }
    }

    for (int i = 0; i < arr_pos_i; i++) {
        printf("%d ", arr_pos[i]);
    }
    for (int i = 0; i < arr_neg_i; i++) {
        printf("%d ", arr_neg[i]);
    }

    return 0;
}