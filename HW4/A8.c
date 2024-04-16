#include <stdio.h>

int main () {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    int max = a > b ? a : b;
    max = c > max ? c : max;

    printf("%d", max);
    return 0;
}
