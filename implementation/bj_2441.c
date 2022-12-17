#include <stdio.h>
void makespace(int space);
int main(void)
{
    int num;
    int n1;
    int space;

    num = 0;
    n1 = 0;
    space = 0;
    scanf("%d", &num);
    while (num--)
    {
        n1 = num;
        makespace(space);
        while (n1-- + 1)
            printf("*");
        printf("\n");
        space++;
    }
    return (0);
}

void makespace(int space)
{
    while(space--)
        printf(" ");
}