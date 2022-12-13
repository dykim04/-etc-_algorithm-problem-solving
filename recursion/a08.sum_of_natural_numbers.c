#include <stdio.h>

int calculate_sum(int );

int main(void)
{
    int sum;

    sum = calculate_sum(10);

    printf("%d", sum);
    return (0);
}

int calculate_sum(int n)
{
    if (n > 0)
        return (calculate_sum(n - 1) + n);
    return (0);
}