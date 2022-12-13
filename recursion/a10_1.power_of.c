int power(int base, int exponent)
{
    if (exponent == 0)
        return (1);
    else
    {
        return (base * power(base, exponent - 1));
    }
}

#include <stdio.h>
int main()
{
    int ans;
    
    ans = power(3, 7);
    printf("%d", ans);

    return (0);
}