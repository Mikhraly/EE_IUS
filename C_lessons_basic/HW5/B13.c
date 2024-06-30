#include <stdio.h>

int main() {
    int number, even_count = 0, odd_count = 0;
    scanf("%d", &number);

    for(; number != 0; number /= 10) {
        number % 10 % 2 == 0 ? even_count++ : odd_count++;
    }

    printf("%d %d", even_count, odd_count);
    return 0;
}