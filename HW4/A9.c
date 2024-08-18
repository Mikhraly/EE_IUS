#include <stdio.h>

int main () {
    int a, b, c, d, e;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

    int max = a > b ? a : b;
    max = c > max ? c : max;
    max = d > max ? d : max;
    max = e > max ? e : max;

    printf("%d", max);
    return 0;
}
