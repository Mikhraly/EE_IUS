#include <stdio.h>

int is_prime(int n);

int main()
{
    int n;
    scanf("%d", &n);

    is_prime(n) ? printf("YES") : printf("NO");
    return 0;
}

int is_prime(int n)
{
    int res = 0;

    if (n < 2) {
        goto exit;
    }

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            goto exit;
        }
    }

    res = 1;
exit:
    return res;
}