#include <stdio.h>

int convert_num(int n, int p)
{
    int res = 0, i = 1;
    
    for (; n >= p; n /= p, i *= 10) {
        res += n % p * i;
    }
    res += n * i;

    return res;
}

int main()
{
    int n, p;
    scanf("%d%d", &n, &p);

    printf("%d", convert_num(n, p));   
    return 0;
}