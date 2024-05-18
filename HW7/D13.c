#include <stdio.h>

void print_simples(int num);
int is_simple(int num);

int main()
{
    int num;
    scanf("%d", &num);

    print_simples(num);
    return 0;
}

void print_simples(int num)
{
    if (num < 2)
        return;

    for (int i = 2; i <= num; i++) {
        if (is_simple(i) && num % i == 0) {
            printf("%d ", i);
            print_simples(num / i);
            break;
        }
    }
}

int is_simple(int num)
{
    int result = 1;

    if (num < 2)
        result = 0;

    for (int i = 2; i < num; i++) {
        if (num % i == 0)
            result = 0;
    }

    return result;
}
