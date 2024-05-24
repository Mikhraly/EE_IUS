#include <stdio.h>

void print_digits_quantity();

int main() {
    print_digits_quantity();
}

void print_digits_quantity()
{
    int count_digits[10] = {0};
    
    int digit = getchar();
    while (digit >= '0' && digit <= '9') {
        count_digits[digit - 0x30]++;
        digit = getchar();
    }

    for (int i = 0; i < 10; i++) {
        if (count_digits[i] != 0) {
            printf("%d %d\n", i, count_digits[i]);
        }
    }
}