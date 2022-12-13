#include <stdio.h>
#include <unistd.h>

int tower_of_hanoi(int n, int from, int aux, int to)
{
    static int x = 0;
    if (n > 0)
    {
        tower_of_hanoi(n - 1, from, to, aux);
        printf("%d -> %d\n", from, to);
        tower_of_hanoi(n - 1, aux, from, to);
        x++;
    }
    return (x);
}

int main(void)
{
    int sum;

    sum = 0;
    sum = tower_of_hanoi(3, 1, 2, 3);
    printf("%d", sum);
    return (0);
}