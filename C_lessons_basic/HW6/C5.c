#include <stdio.h>

int sum(int n)
{
    int sum = 0;

    for (int i = 0; i <= n; i++)
        sum += i;

    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", sum(n));
    return 0;
}