#include <stdio.h>

#define STR 5
#define COL 5
#define SIZE 5

int arithmetic_mean(int size, int arr[STR][COL]);


int main() {
    int arr[STR][COL] = {0};

    for (int i = 0; i < STR; i++) {
        for (int j = 0; j < COL; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int arithmetic = arithmetic_mean(SIZE, arr);
    int count = 0;
    for (int i = 0; i < STR; i++) {
        for (int j = 0; j < COL; j++) {
            if (arr[i][j] > arithmetic) {
                count++;
            }
        }
    }

    printf("%d", count);
    return 0;
}


int arithmetic_mean(int size, int arr[5][5])
{
    int sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                sum += arr[i][j];
            }
        }
    }
    return sum / size;
}