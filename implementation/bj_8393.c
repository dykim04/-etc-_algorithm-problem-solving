#include <stdio.h>
int main(void)
{
    int i;
    int sum;
    int n;

    i = 0;
    sum = 0;
    n = 0;
    scanf("%d", &i);
    while (n++ < i)
        sum += n;
    printf("%d", sum);
    return(0);
}