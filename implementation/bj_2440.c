#include <stdio.h>
int main(void)
{
    int num;
    int n1;

    num = 0;
    n1 = 0;
    scanf("%d", &num);
    while (num--)
    {
        n1 = 0;
        while (n1++ -1 < num)
            printf("*");
        printf("\n");
    }
    return (0);
}