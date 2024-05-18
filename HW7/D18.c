#include <stdio.h>

void print_digits(int n);

int main()
{
    int n;
    scanf("%d", &n);

    print_digits(n);
    return 0;
}

void print_digits(int n)
{
    if (n > 9) {
        print_digits(n / 10);
        printf("%d ", n % 10);
    } else {
        printf("%d ", n);
    }
}