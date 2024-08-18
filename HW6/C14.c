#include <stdio.h>

int is_numbers_sum_even(int n);

int main()
{
    int n;
    scanf("%d", &n);

    is_numbers_sum_even(n) ? printf("YES") : printf("NO");
    return 0;
}

int is_numbers_sum_even(int n)
{
    int sum = 0;
    for (; n > 0; n /= 10) {
        sum += n % 10;
    }
    return sum % 2 == 0 ? 1 : 0;
}