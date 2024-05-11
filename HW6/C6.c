#include <stdio.h>
#include <inttypes.h>

int main()
{
    uint64_t n, res = 1;
    scanf("%"SCNu64, &n);

    for (uint64_t i = 1; i < n; i++) {
        res *= 2;
    }

    printf("%"PRIu64, res);
    return 0;
}