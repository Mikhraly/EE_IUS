#include <stdio.h>

int main()
{
    int arr[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    float result = 0;
    for (int i = 0; i < 5; i++) {
        result += arr[i];
    }
    result /= 5;

    printf("%.3f", result);
    return 0;
}