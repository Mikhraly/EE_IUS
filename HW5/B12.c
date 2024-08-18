#include <stdio.h>

int main() {
    int number, min, max;
    scanf("%d", &number);

    min = max = number % 10;
    number /= 10;

    for(; number != 0; number /= 10) {
        int digit = number % 10;

        min = digit < min ? digit : min;
        max = digit > max ? digit : max;
    }

    printf("%d %d", min, max);
    return 0;
}