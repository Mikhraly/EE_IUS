#include <stdio.h>

int main() {
    int number;
    scanf("%d", &number);

    for(; number != 0; number /= 10) {
        int digit = number % 10;

        if (digit <= number / 10 % 10) {
            printf("NO");
            return 0;
        }
    }

    printf("YES");
    return 0;
}