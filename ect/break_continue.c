#include <stdio.h>
int main(void)
{
    int n1;

    n1 = 0;
    while(n1 < 101)
    {
        if (n1 % 2 == 0)
        {
            printf("%d\n", n1);
            n1++;
        }
        else
        {
            n1++;
            break ;
        }
    }
    return (0);
}