#include <stdio.h>

#define SIZE 10

int num_quantity(int* arr, int size, int num);

int main()
{
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    int num = 0;
    int quantity = 0;
    for (int i = 0, count = 0; i < SIZE; i++, count = 0) {
        count = num_quantity(arr, SIZE, arr[i]);
        if (count > quantity) {
            num = arr[i];
            quantity = count;
        }
    }

    printf("%d", num);
    return 0;
}

int num_quantity(int* arr, int size, int num)
{
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            count++;
        }
    }
    return count;
}