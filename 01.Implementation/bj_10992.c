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
void make_line(int i)
{
    i--;
    make_star(1);
    make_space((2 * i) - 1);
    make_star(1);
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
        else if(i < num)
            make_line(i);
        else
            make_star((2 * i) - 1);
        printf("\n");
    }
    return (0);
}