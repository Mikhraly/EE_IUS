#include <stdio.h>

#define SIZE 10

int is_two_same(int size, int a[]);

int main() {
    int arr[SIZE] = {1, 2, 3, 4, 5, 5, 7, 8, 9, 10};
    printf("%d", is_two_same(SIZE, arr));
    return 0;
}

int is_two_same(int size, int a[])
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[i] == a[j]) {
                return 1;
            }
        }
    }
    return 0;
}