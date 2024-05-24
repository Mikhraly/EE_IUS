#include <stdio.h>

int main() {
    char c = getchar();
    char n = getchar();
    if ((c - n) % 2 == 0) {
        printf("BLACK");
    } else {
        printf("WHITE");
    }

    return 0;
}