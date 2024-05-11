#include <stdio.h>

int digit_to_num(char c);

int main()
{
    int sum = 0, num;
    for (char c; (c = getchar()) != '.';) {
        num = digit_to_num(c);
        if (num < 10)
            sum += num;
    }

    printf("%d", sum);
    return 0;
}

int digit_to_num(char c)
{
    if (c >= '0' && c <= '9') {
        return c - 0x30;
    } else {
        return c;
    }
}