#include <stdio.h>

int main(int argc, char *argv)
{
    unsigned int n, k;
    scanf("%u%u", &n, &k);

    if (n < 1 || k < 1 || k > 31)
        return 1;

    unsigned int mask = (1 << k) - 1;
    unsigned int max = n & mask;
    while (n > 0) {
        if (((n = n >> 1) & mask) > max)
            max = n;
    }

    printf("%u", max); 

    return 0;
}