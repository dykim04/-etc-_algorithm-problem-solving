// formula
// nCr = n! / r!(n-r)!
int factorial(int n)
{
    if (n == 0)
        return (1);
    return (n * factorial(n - 1));
}

int C(int n, int r)
{
    int denominator = 0;
    int numerator_1 = 0;
    int numerator_2 = 0;

    denominator = factorial(n);
    numerator_1 = factorial(r);
    numerator_2 = factorial(n - r);
    
    return (denominator / (numerator_1 * numerator_2));
}

#include <stdio.h>
int main()
{
    printf("%d", C(4, 2));

    return (0);
}