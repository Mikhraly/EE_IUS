#include <stdio.h>
#include <stdint.h>

#define SIZE 10

int main()
{
    int32_t arr[SIZE];
    for (int32_t i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    int max1 = arr[0], max2 = arr[1];
    for (int32_t i = 2; i < SIZE; i++) {
        if (arr[i] > max1 || arr[i] > max2) {
            if (max1 < max2)
                max1 = arr[i];
            else
                max2 = arr[i];
        }

    }

    printf("%d", max1 + max2);
    return 0;
}