#include <stdio.h>

int main() {
    int number, even_count = 0;
    scanf("%d", &number);

    while (number != 0) {
        if (number % 2 == 0) {
            even_count++;
        }
        scanf("%d", &number);
    }

    printf("%d", even_count);
    return 0;
}