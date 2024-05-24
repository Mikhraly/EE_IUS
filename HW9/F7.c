#include <stdio.h>

#define SIZE 10

 int compression(int a[], int b[], int N);

int main() {
    int arr[SIZE] = {1, 0, 0, 0, 1, 1, 0, 0, 0, 1};
    int arr1[SIZE] = {0};
    printf("%d\n", compression(arr, arr1, SIZE));
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr1[i]);
    }
    return 0;
}

int compression(int a[], int b[], int N)
{
    int b_i = 0;
    int count_0 = 0;
    int count_1 = 0;

    if (a[0] == 1)
        b[b_i++] = 0;

    for (int i = 0; i < N; i++) {
        if (a[i] == 0) {
            if (count_1 != 0) {
                b[b_i++] = count_1;
                count_1 = 0;
            }
            count_0++;
        }
        if (a[i] == 1) {
            if (count_0 != 0) {
                b[b_i++] = count_0;
                count_0 = 0;
            }
            count_1++;
        }
    }

    if (count_1 != 0) {
        b[b_i++] = count_1;
        count_1 = 0;
    }

    if (count_0 != 0) {
        b[b_i++] = count_0;
        count_0 = 0;
    }

    return b_i;
}