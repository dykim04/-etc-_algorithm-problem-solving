#include <stdio.h>

void tree_recur(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        tree_recur(n - 1);
        tree_recur(n - 1);
    }
}

int main(void)
{
    tree_recur(4);
    return (0);
}