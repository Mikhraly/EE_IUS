#include <stdio.h>

int is_digit(char c);

int main()
{
    int digit_count = 0;
    for (char c; (c = getchar()) != '.';) {
        if (is_digit(c))
            digit_count++;
    }

    printf("%d", digit_count);
    return 0;
}

int is_digit(char c)
{
    if (c >= '0' && c <= '9') {
        return 1;
    } else {
        return 0;
    }
}