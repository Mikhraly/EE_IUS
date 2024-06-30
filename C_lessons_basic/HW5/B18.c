#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);

    int a = 1, b = 1;

    for (int i = 1; i <= num; i++) {
        if (i == 1 || i == 2) {
            printf("1 ");
        } else {
            int c = a + b;
            printf("%d ", c);
            a = b;
            b = c;
        }
    }

    return 0;
}