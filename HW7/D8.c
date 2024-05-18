#include <stdio.h>

void print_numbers(int a, int b);

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    
    print_numbers(a, b);
    return 0;
}

void print_numbers(int a, int b)
{
    printf("%d ", a);

    if (a < b) {
        print_numbers(++a, b);
    } else if (a > b) {
        print_numbers(--a, b);
    } else {
        return;
    }
}