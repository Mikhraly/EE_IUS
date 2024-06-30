#include <stdio.h>

int numbers_sum(int num);

int main()
{
    int num;
    scanf("%d", &num);
    
    printf("%d", numbers_sum(num));
    return 0;
}

int numbers_sum(int num)
{
    if (num > 1)
        return num + numbers_sum(num - 1);
    else
        return 1;
}