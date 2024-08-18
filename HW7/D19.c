#include <stdio.h>

int a_counter(void);

int main()
{
    printf("%d", a_counter());
    return 0;
}

int a_counter(void)
{
    char c;
    scanf("%c", &c);

    if (c == '.')
        return 0;

    if (c == 'a')
        return 1 + a_counter();
    else
        return 0 + a_counter();
}