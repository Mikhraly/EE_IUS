#include <stdio.h>

int recurs_power(int n, int p);

int main()
{
    int n, p;
    scanf("%d%d", &n, &p);

    printf("%d", recurs_power(n, p));
    return 0;
}

int recurs_power(int n, int p)
{
    if (p > 0)
        return n * recurs_power(n, --p);
    else
        return 1;
}