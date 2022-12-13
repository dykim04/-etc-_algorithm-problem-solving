unsigned long long int fibonacci_iterative(unsigned long long int n)
{
    unsigned long long int      t0  = 0;
    unsigned long long int      t1  = 1;
    unsigned long long int      sum = 0;
    unsigned long long int      i   = 1;
    
    if (n <= 0)
        return (0);
    if (n == 1)
        return (1);
    while (i < n)
    {
        sum = t0 + t1;
        t0  = t1;
        t1  = sum;
        i++;
    }
    return (sum);
}

#include <stdio.h>
int main()
{
    unsigned long long int i = 0;

    while (i < 50)
    {
        printf("[%lld] %lld\n", i, fibonacci_iterative(i));
        i++;
    }
    return (0);
}