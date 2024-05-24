#include <stdio.h>

void print_digit(char s[]);

int main() {
    print_digit("Hello123 world77.");
}

void print_digit(char s[])
{
    int count_digits[10] = {0};

    int i = 0;
    for (char c = s[i]; c != '\0'; c = s[++i]) {
        if (c >= '0' && c <= '9') {
            count_digits[c - 0x30]++;
        }
    }

    for (int i = 0; i < 10; i++) {
        if (count_digits[i] != 0) {
            printf("%d %d\n", i, count_digits[i]);
        }
    }
}