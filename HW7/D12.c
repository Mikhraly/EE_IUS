#include <stdio.h>

void print_nums(int start_num, int quantity);

int main()
{
    int num;
    scanf("%d", &num);

    print_nums(1, num);
    return 0;
}

void print_nums(int start_num, int quantity)
{
    int count = 0;
    for (; count < start_num && count < quantity; count++) {
        printf("%d ", start_num);
    }

    if (count < quantity)
        print_nums(start_num + 1, quantity - start_num);
    else
        return;
}
