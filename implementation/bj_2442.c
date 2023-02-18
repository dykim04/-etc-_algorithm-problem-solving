#include <stdio.h>
void make_space(int space)
{
    while (space--)
        printf(" ");
}
int main(void)
{
    int n;
    int i;
    int k;
    int space;

    n = 0;
    i = 1;
    k = 0;
    scanf("%d", &n);
    space = n -1;
    while (i < n + 1)
    {
        k = 0;
        make_space(space);
        while (k < i)
        {
            printf("*");
            k++;
        }
        k = 0;
        while (k < i - 1)
        {
            printf("*");
            k++;
        }
        printf("\n");
        space--;
        i++;
    }
    return (0);
}