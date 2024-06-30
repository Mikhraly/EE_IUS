#include <stdio.h>

void print_str_revers();

int main()
{
    print_str_revers();
    return 0;
}

void print_str_revers()
{
    char ch;
    scanf("%c", &ch);

    if (ch != '.') {
        print_str_revers();
        printf("%c", ch);
    }
}