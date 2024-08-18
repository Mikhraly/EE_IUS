#include <stdio.h>
#include <stdint.h>

int find_max();

int main()
{
    printf("%d", find_max());
    return 0;
}

int find_max()
{
    int32_t num;
    scanf("%d", &num);

    if (num == 0)
        return INT32_MIN;
    
    int32_t next = find_max();
    return num > next ? num : next;
}