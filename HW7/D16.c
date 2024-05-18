#include <stdio.h>

int is2pow(int num);

int main()
{
    int num;
    scanf("%d", &num);

    is2pow(num) ? printf("YES") : printf("NO");
    return 0;
}

int is2pow(int num)
{
    if (num == 1)
        return 1;

    return !(num % 2) * is2pow(num / 2);
}