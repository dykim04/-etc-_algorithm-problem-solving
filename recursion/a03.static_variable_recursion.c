#include <stdio.h>

int recursion(int n)
{
    static int x = 0; // also can use Global Variable to return same result    
    // if use int x = 0 -> the result will be 5 instead of 25
    if (n > 0)
    {
        x++;
        return recursion(n - 1) + x;
    }
    return (0);
}

int main(void)
{
    int r;
    r = recursion(5);
    printf("%d\n", r);
    return (0);
}