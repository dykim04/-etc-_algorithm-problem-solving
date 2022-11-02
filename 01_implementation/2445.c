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
    space = 2 * (num -1);
    while (i++ < num)
    {
        make_star(i);
        make_space(space);
        make_star(i);
        space -= 2;
        printf("\n");
    }
    i -= 2;
    space += 4;
    num --;
    while (num--)
    {
        make_star(i);
        make_space(space);
        make_star(i);
        space += 2;
        i--;
        printf("\n");
    }
    return (0);
}
