#include <stdio.h>
#include <stdint.h>

#define SIZE 10

int main()
{
    int32_t arr[SIZE];
    for (int32_t i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    int32_t
        max_index = 0,
        max = INT32_MIN,
        min_index = 0,
        min = INT32_MAX;
    
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] > max) {
            max = arr[i];
            max_index = i;
        }
        if (arr[i] < min) {
            min = arr[i];
            min_index = i;
        }
    }

    printf("%d %d %d %d", max_index + 1, max, min_index + 1, min);
    return 0;
}