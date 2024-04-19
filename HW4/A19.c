#include <stdio.h>

int main () {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    int c_max = a + b;
    int c_min = a > b ? a - b : b - a;

    if (c < c_max && c > c_min) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
