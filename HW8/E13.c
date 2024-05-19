#include <stdio.h>

#define SIZE 10

int main()
{
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    int arr1[SIZE] = {0};
    int count = 0;
    for (int i = 0, j = 0; i < SIZE; i++) {
        if (arr[i] / 10 % 10 == 0) {
            arr1[j] = arr[i];
            j++;
            count++;
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%d ", arr1[i]);
    }

    return 0;
}