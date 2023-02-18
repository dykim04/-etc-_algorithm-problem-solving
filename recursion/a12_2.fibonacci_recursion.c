int fibonacci_recursion(int n)
{
    if (n <= 1)
        return (n);
    return (fibonacci_recursion(n - 1) + fibonacci_recursion(n - 2));
}

#include <stdio.h>
int main()
{
    int n;

    n = 0;
    while (n++ < 50)
    {
        printf("[%d] %d\n", n, fibonacci_recursion(n));
    }
    
    return (0);
}

// time complexity = O(2^n)