#include <stdio.h>
#include <stdint.h>

#define SIZE 30

int get_min_index(int size, int arr[]);


int main()
{
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    int min_index = get_min_index(SIZE, arr);
    arr[min_index] = INT32_MAX;
    int min_index_1 = get_min_index(SIZE, arr);

    if (min_index <= min_index_1) {
        printf("%d %d", min_index, min_index_1);
    } else {
        printf("%d %d", min_index_1, min_index);
    }

    return 0;
}


int get_min_index(int size, int arr[])
{
    int min = INT32_MAX;
    int min_i;

    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
            min_i = i;
        }
    }

    return min_i;
}