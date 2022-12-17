int power(int base, int exponent)
{
    if (exponent == 0)
        return (1);
    if (exponent % 2 != 0)
        return (base * power(base, exponent - 1));
    return (power(base * base, exponent / 2));
}

#include <stdio.h>
int main()
{
    int ans;
    
    ans = power(2, 10);
    printf("%d", ans);

    return (0);
}