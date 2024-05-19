#include <stdio.h>
#include <stdint.h>

#define SIZE 10

int main()
{
    int32_t arr[SIZE];
    for (int32_t i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for (int32_t i = 0; i < SIZE; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
        }

    }

    printf("%d", sum);
    return 0;
}