#include <stdio.h>

#define SIZE 10

int count_between(int from, int to, int size, int a[]);


int main() {
    int arr[SIZE] = {1, -2, -3, -4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("%d", count_between(4, 6, SIZE, arr));
    return 0;
}


int count_between(int from, int to, int size, int a[])
{
    int count = 0;
    
    for (int i = 0; i < size; i++) {
        if (a[i] >= from && a[i] <= to) {
            count++;
        }
    }

    return count;
}