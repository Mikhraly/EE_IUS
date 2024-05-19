#include <stdio.h>
#include <stdint.h>

#define SIZE 12

int main()
{
    int32_t arr[SIZE];
    for (int32_t i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    float average = 0;
    for (int32_t i = 0; i < SIZE; i++) {
        average += arr[i];
    }
    average /= SIZE;

    printf("%.2f", average);
    return 0;
}