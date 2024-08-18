#include <stdio.h>

int get_matrix_trace(int size, int arr[5][5]);


int main() {
    int arr[5][5] = {0};

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("%d", get_matrix_trace(5, arr));
    return 0;
}


int get_matrix_trace(int size, int arr[5][5])
{
    int matrix_trace = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                matrix_trace += arr[i][j];
            }
        }
    }
    return matrix_trace;
}