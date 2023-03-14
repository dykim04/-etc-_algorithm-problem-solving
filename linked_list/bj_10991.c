#include <stdio.h>
void make_space(int space)
{
    while (space--)
        printf(" ");
}
void make_star(int i)
{
    while (i--)
        printf("*");
}
void make_star1(int i)
{
    while(i-- - 1)
        printf("* ");
    printf("*");
}
int main(void)
{
    int num;
    int i;
    int space;

    num = 0;
    i = 0;
    space = 0;
    scanf("%d", &num);
    space = num - 1;
    while (i++ < num)
    {
        make_space(space--);
        if (i == 1)
            make_star(1);
        else
            make_star1(i);
        printf("\n");
    }
    return (0);
}