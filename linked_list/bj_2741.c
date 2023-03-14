#include <stdio.h>
int main(void)
{
    int n;
    int n1;

    n = 0;
    n1 = 0;
    scanf("%d", &n);
    while (n1 < n)
    {
        printf("%d\n", n1 + 1);
        n1++;
    }
    return (0);
}
