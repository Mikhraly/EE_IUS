#include <stdio.h>
#include <math.h>

#define RAD (180/3.14)

float sinus(float x);
int factorial(int n);

int main()
{
    int x;
    scanf("%d", &x);

    printf("%.3f", sinus(x / RAD));
    return 0;
}

float sinus(float x)
{
    float res = x;

    for (int n = 3, sign = -1; n < 10; n += 2, sign = -sign) {
        res = res + sign * pow(x, n)/factorial(n);
    }
    
    return res;
}

int factorial(int n)
{
    int res = 1;

    for (int i = 1; i <= n; i++)
        res *= i;
    
    return res;
}