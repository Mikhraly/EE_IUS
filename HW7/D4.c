#include <stdio.h>

void print_digits(int num);

int main()
{
    int num;
    scanf("%d", &num);
    
    print_digits(num);
    return 0;
}

void print_digits(int num)
{
    if (num > 9) {
        print_digits(num / 10);
        printf("%d ", num % 10);
    } else {
        printf("%d ", num);
    }

}