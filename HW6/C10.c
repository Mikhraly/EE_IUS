#include <stdio.h>
#include <stdint.h>

void print_simple(int num);
int get_next_simple(int num);

int main()
{
    int num;
    scanf("%d", &num);

    print_simple(num);
    return 0;
}

void print_simple(int num)
{
    int simple = 2;
    for (; num > 1; num /= simple) {

        while (num % simple != 0)
            simple = get_next_simple(simple);

        printf("%d ", simple);
    }
}

int get_next_simple(int num)
{
    for (num++; num < UINT32_MAX; num++) {
        uint32_t count = 0;

        for (uint32_t i = 2; i < num; i++) {
            if (num % i == 0) {
                count++;
            }
        }

        if (count == 0)
            return num;
    }

    return -1;
}