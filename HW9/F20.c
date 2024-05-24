#include <stdio.h>

#define SIZE 10

int main() {
    int arr[SIZE] = {0};

    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    int even = 0;
    int odd = 0;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    if (even > odd) {
        for (int i = 0; i < SIZE; i++) {
            if (arr[i] % 2 == 1) {
                int res = 1;
                for (int n = arr[i]; n > 0; n /= 10) {
                    if (n % 10 % 2 == 1) {
                        res *= n % 10;
                    }
                }
                arr[i] = res;
            }
        }
    } else {
        for (int i = 0; i < SIZE; i++) {
            if (arr[i] % 2 == 0) {
                int res = 1;
                for (int n = arr[i]; n > 0; n /= 10) {
                    if (n % 10 % 2 == 0) {
                        res *= n % 10;
                    }
                }
                arr[i] = res;
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}