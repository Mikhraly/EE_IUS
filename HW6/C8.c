#include <stdio.h>

char convert_let(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - ('a' - 'A');
    else
        return c;
}

int main()
{
    for (char c = getchar(); c != '.'; c = getchar()) {
        printf("%c", convert_let(c));
    }

    return 0;
}