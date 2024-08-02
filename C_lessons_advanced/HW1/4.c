#include <stdio.h>

int main(int argc, char *argv)
{
    unsigned int n, k;
    scanf("%u%u", &n, &k);

    if (n < 1 || k < 1 || k > 31)
        return 1;

    unsigned int mask = (1 << k) - 1;
    printf("%u",  n & mask); 

    return 0;
}