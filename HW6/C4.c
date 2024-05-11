#include <stdio.h>
#include <stdint.h>

int32_t f(int32_t x)
{
    if (x < -2) {
        return 4;
    } else if (x >= 2) {
        return x*x + 4*x + 5;
    } else {
        return x*x;
    }
}

int main()
{
    int32_t x, max_res = INT32_MIN;

    for (scanf("%d", &x); x != 0; scanf("%d", &x)) {
        int32_t temp;
        if ((temp = f(x)) > max_res) {
            max_res = temp;
        }
    }
    
    printf("%d", max_res);
    return 0;
}