#include <stdio.h>

void recur_1(int );
void recur_2(int );

void recur_1(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        recur_2(n - 1);
    }
}

void recur_2(int n)
{
    if (n > 1)
    {
        printf("%d ", n);
        recur_1(n / 2);
    }
}

int main(void)
{
    recur_1(20);

    return (0);
}