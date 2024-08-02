#include <stdio.h>

int main(int argc, char *argv)
{
    int n, k;
    scanf("%u%u", &n, &k);

    if (n < 1 || k < 1 || k > 31)
        return 1;

    n = n << (32 - k) | n >> k;
    printf("%u", n);

    return 0;
}