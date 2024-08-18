#include <stdio.h>

#define SIZE 12

int count_bigger_abs(int n, int a[]);

int main() {
    int arr[SIZE] = {60, 50, -89, -71, 6, 40, 61, -75, 53, 64, -79, -97};

    for (int i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("%d", count_bigger_abs(SIZE, arr));
    return 0;
}


int count_bigger_abs(int n, int a[])
{
    int max = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (-a[i] > max)
            count++;
    }

    return count;
}