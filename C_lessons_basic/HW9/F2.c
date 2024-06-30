#include <stdio.h>

#define SIZE 5

void sort_even_odd(int n, int a[]);

int main() {
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    sort_even_odd(SIZE, arr);

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
}

void sort_even_odd(int n, int a[])
{
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0)
            continue;

        for (int j = i; j > 0 && a[j - 1] % 2 != 0; j--) {
            int temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
        }
    }
}