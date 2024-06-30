#include <stdio.h>

#define SIZE 12

int sum_between_ab(int from, int to, int size, int a[]);


int main() {
    int arr[SIZE] = {60, 50, 89, 71, 6, 40, 61, 75, 53, 64, 79, 97};

    for (int i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("%d", sum_between_ab(53, 53, SIZE, arr));
    return 0;
}


int sum_between_ab(int from, int to, int size, int a[])
{
    int sum = 0;
    
    if (from > to) {
        int temp = from;
        from = to;
        to = temp;
    }

    for (int i = 0; i < size; i++) {
        if (a[i] >= from && a[i] <= to) {
            sum += a[i];
        }
    }

    return sum;
}