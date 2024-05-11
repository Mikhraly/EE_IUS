#include <stdio.h>

int power(int num, int pow)
{
    int res = 1;

    for (int i = 0; i < pow; i++) {
        res *= num;
    }

    return res;
}

int main()
{
    int num, pow;
    scanf("%d%d", &num, &pow);
    
    printf("%d", power(num, pow));
    return 0;
}