#include <stdio.h>

#define SIZE 10

void change_max_min(int size, int a[]);


int main() {
    int arr[SIZE] = {1, -2, -3, -4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    change_max_min(SIZE, arr);

    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


void change_max_min(int size, int a[])
{
    int* min = a;
    int* max = a;

    for (int i = 0; i < size; i++) {
        if (a[i] < *min) {
            min = a + i;
        }
        if (a[i] > *max) {
            max = a + i;
        }
    }

    int temp = *min;
    *min = *max;
    *max = temp;
}