#include <stdio.h>
int main(void)
{
    long long num;
    long long i;
    long long k;
    long long arr[101][10];
    long long mod;
    
    num = 0;
    mod = 1000000000;
    scanf("%lld", &num);
    i = -1;
    k = 0;
    while (i++ < 9)
        arr[0][i] = 1;
    arr[0][0] = 0;
    while (k++ < num)
    {
        i = -1;
        while (i++ < 9)
        {
            if (i == 0)
                arr[k][i] = (arr[k - 1][i + 1]) % mod;
            if (i >= 1 && i <= 8)
                arr[k][i] = (arr[k - 1][i - 1] + arr[k - 1][i + 1]) % mod;
            if (i == 9)
                arr[k][i] = (arr[k - 1][i - 1]) % mod;
        }
    }
    // i = -1;
    // k = -1;
    // while (i++ < num - 1)
    // {
    //     k = -1;
    //     printf("row = %lld  ", i);
    //     while (k++ < 9)
    //         printf("%lld ", arr[i][k]);
    //     printf("\n");
    // }
    long long sum;

    sum = 0;
    i = -1;
    while (i++ < 9)
        sum += (arr[num - 1][i]) % mod;
    printf("%lld", sum % mod);
    return (0);
}