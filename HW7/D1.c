#include <stdio.h>

void print_numbers(int num);

int main()
{
    int num;
    scanf("%d", &num);
    
    print_numbers(num);
    return 0;
}

void print_numbers(int num)
{
    if (num > 1)
        print_numbers(num - 1);

    printf("%d ", num);
}