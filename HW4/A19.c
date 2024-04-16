#include <stdio.h>

int main () {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    if (c < a + b && c > (a > b ? a - b : b - a)) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
