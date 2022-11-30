#include <stdio.h>
int main(void)
{
    int n;

    n = 0;
    scanf("%d", &n);
    while (n)
    {
        printf("%d\n", n);
        n -= 1;
    }
    return (0);
}