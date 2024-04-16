#include <stdio.h>

int main () {
    int a, b, c, d, e;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

    int min = a < b ? a : b;
    min = c < min ? c : min;
    min = d < min ? d : min;
    min = e < min ? e : min;

    int max = a > b ? a : b;
    max = c > max ? c : max;
    max = d > max ? d : max;
    max = e > max ? e : max;

    printf("%d", max + min);
    return 0;
}
