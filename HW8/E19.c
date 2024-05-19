#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[10] = {0};
    int arr_i = 0;

    for (int number = n % 10; n > 0; n /= 10, number = n % 10) {
        arr[arr_i++] = number;
    }

    for (int i = arr_i - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

    return 0;
}