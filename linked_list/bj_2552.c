#include <stdio.h>
void make_space(int space)
{
    while (space--)
        printf(" ");
}
void make_star(int i)
{
    while(i--)
        printf("*");
}
int main(void)
{
    int space;
    int num;
    int i;

    space = 0;
    num = 0;
    i = 0;

    scanf("%d", &num);
    space = num - 1;
    while (i++ < num)
    {
        make_space(space--);
        make_star(i);
        printf("\n");
    }
    num -= 1;
    space += 1;
    i -= 1;
    while (num--)
    {
        make_space(++space);
        make_star(--i);
        printf("\n");
    }
    return (0);
}
