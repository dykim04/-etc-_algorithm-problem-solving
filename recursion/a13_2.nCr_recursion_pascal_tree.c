int c(int n, int r)
{
    if (r == 0 || n == r)
        return (1);
    else
        return (c(n - 1, r - 1) + c(n - 1, r));
}

#include <stdio.h>
int main()
{
    printf("%d", c(46, 23));

    return (0);
}