#include <stdio.h>

int main() {
    for (char a = getchar(); a != '.'; a = getchar()) {
        if (a >= 0x41 && a <= 0x5A) {
            printf("%c", a + 0x20);
        } else {
            printf("%c", a);
        }
    }

    return 0;
}