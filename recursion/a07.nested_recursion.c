#include <stdio.h>

int recurse(int n)
{
    if (n > 100)
        return (n - 10);
    return recurse(recurse(n + 11));
}

int main(void)
{
    int n;

    n = recurse(5);
    printf("%d", n);

    return (0);
}