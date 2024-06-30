#include <stdio.h>

#define SIZE 20

void sort_array(int size, int a[]);

int main() {
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    sort_array(20, arr);

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
}

void sort_array(int size, int a[])
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}