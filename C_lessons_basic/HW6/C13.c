#include <stdio.h>
#include <math.h>

#define RAD (180/3.14)

float cosinus(float x);
int factorial(int n);

int main()
{
    int x;
    scanf("%d", &x);

    printf("%.3f", cosinus(x / RAD));
    return 0;
}

float cosinus(float x)
{
    float res = 1;

    for (int n = 2, sign = -1; n < 33; n += 2, sign = -sign) {
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