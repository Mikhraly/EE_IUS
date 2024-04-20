#include <stdio.h>

int main() {
    int number, reverse = 0;
    scanf("%d", &number);

    for(; number != 0; number /= 10) {
        reverse = reverse * 10 + number % 10;
    }

    printf("%d", reverse);
    return 0;
}