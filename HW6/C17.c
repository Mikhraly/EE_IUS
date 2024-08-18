#include <stdio.h>

int is_happy_number(int n);

int main()
{
    int n;
    scanf("%d", &n);

    is_happy_number(n) ? printf("YES") : printf("NO");
    return 0;
}

int is_happy_number(int n)
{
    int sum = 0, prod = 1;
    for (; n > 0; n /= 10) {
        sum += n % 10;
        prod *= n % 10;
    }
    return sum == prod ? 1 : 0;
}