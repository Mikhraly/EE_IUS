#include <stdio.h>

int main() {
    int count = 0;
    char c_prev, c;

    c_prev = c = getchar();

    for (; c != '.'; c = getchar()) {
        if (c == c_prev) {
            count++;
            c_prev = c;
        } else {
            printf("%c%d", c_prev, count);
            count = 1;
            c_prev = c;
        }
    }
    printf("%c%d", c_prev, count);

    return 0;
}