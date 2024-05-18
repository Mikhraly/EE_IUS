#include <stdio.h>

void print_digits_revers(int num);

int main()
{
    int num;
    scanf("%d", &num);
    
    print_digits_revers(num);
    return 0;
}

void print_digits_revers(int num)
{
    if (num > 9) {
        printf("%d ", num % 10);
        print_digits_revers(num / 10);
    } else {
        printf("%d ", num);
    }

}