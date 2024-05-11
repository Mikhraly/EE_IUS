#include <stdio.h>

int grow_up(int n);

int main()
{
    int n;
    scanf("%d", &n);

    grow_up(n) ? printf("YES") : printf("NO");
    return 0;
}

int grow_up(int n)
{
    int res = 1;
    int prev = n % 10;
    n /= 10;

    for (; n > 0; prev = n % 10, n /= 10) {
        if (n % 10 < prev) {
            continue;
        } else {
            res = 0;
            break;
        }
    }

    return res;

}