#include <stdio.h>

void tail_recur(int n)
{
    if (n > 0)
    {
        tail_recur(n - 1);
        printf("%d", n);
    }
}

int main(void)
{
    int x = 3;
    tail_recur(x);
    return (0);
}