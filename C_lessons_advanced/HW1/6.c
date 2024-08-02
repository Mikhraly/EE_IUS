#include <stdio.h>

int main(int argc, char *argv)
{
    unsigned int n;
    scanf("%u", &n);

    if (n < 0)
        return 1;

    unsigned int count = n & 1;
    while (n > 0) {
        if (((n = n >> 1) & 1))
            count++;
    }

    printf("%u", count); 

    return 0;
}