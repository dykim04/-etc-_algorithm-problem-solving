int fibonacci_memoization(int n)
{
    static int buff[1001] = {-1, };

    if (n <= 1)
    {
        buff[n] = n;
        
        return (n);
    }
    else
    {
        if (buff[n - 2] == -1)
            buff[n - 2] = fibonacci_memoization(n - 2);
        if (buff[n - 1] == -1)
            buff[n - 1] = fibonacci_memoization(n - 1);
        buff[n] = buff[n - 2] + buff[n - 1];
        return (buff[n - 2] + buff[n - 1]);
    }    
}

#include <stdio.h>
int main()
{
    int n = 0;
    while (n++ < 50)
    {
        printf("n:%d -> %d\n", n, fibonacci_memoization(n));
    }

    return (0);
}

// time complexity = O(n)