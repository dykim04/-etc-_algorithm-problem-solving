#include <stdio.h>
int main(void)
{
    int base;
    int times;

    base = 0;
    times = 1;
    scanf("%d", &base);
    while (times <= 9)
    {
        printf("%d * %d = %d\n", base, times, base * times);
        times++;
    }
    return (0);
}