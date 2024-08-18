#include <stdio.h>

int find_max_array(int size, int a[]);

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 66, 7, 8, 9, 0};
    printf("%d", find_max_array(10, arr));
}

int find_max_array(int size, int a[])
{
    int max = a[0];

    for (int i = 0; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    return max;
}