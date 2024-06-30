#include <stdio.h>

#define STR 10
#define COL 10

int get_max(int size, int* arr);


int main() {
    int arr[STR][COL] = {0};

    for (int i = 0; i < STR; i++) {
        for (int j = 0; j < COL; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int sum = 0;
    for (int i = 0; i < STR; i++) {
        sum += get_max(COL, &arr[i][0]);
    }

    printf("%d", sum);
    return 0;
}


int get_max(int size, int* arr)
{
    int max = *arr;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}