#include <stdio.h>

void head_recur(int n)
{
    if (n > 0)
    {
        printf("%d", n);
        head_recur(n - 1);
    }
}

int main(void)
{
    int x = 3;
    head_recur(x);
    return (0);
}