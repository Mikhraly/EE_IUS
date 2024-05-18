#include <stdio.h>

int is_prime(int n, int divider);

int main()
{
    int n;
    scanf("%d", &n);

    is_prime(n, 2) ? printf("YES") : printf("NO");
    return 0;
}

int is_prime(int n, int divider)
{
    if (n < 2)
        return 0;

    if (n == divider)
        return 1;

    if (n % divider)
        return 1 * is_prime(n, ++divider);
    else
        return 0;
}