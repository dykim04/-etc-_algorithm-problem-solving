#include <stdio.h>

int factorial(int );

int main(void)
{
    int ans;
    ans = factorial(10);
    printf("%d", ans);

    return (0);
}

int factorial(int n)
{
    if (n > 0)
    {
        if (n > 1)
            printf(" %d *", n);
        if (n == 1)
            printf(" 1 = ");
        return (n * factorial(n - 1));
    }
    return (1);
}