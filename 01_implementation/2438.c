#include <stdio.h>
int main(void)
{
    int n;
    int i;
    int k;

    n = 0;
    i = 1;
    k = 0;
    scanf("%d", &n);
    while (i < n + 1)
    {
        k = 0;
        while (k < i)
        {
            printf("*");
            k++;
        }
        printf("\n");
        i++;
    }
    return (0);
}