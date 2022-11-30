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

// #include <stdio.h>
// #define mod 1000000000
// int main(void){
//     int N;
//     int Dp[101][10] = {};
//     int sum = 0;
//     scanf("%d", &N);
//     for (int i = 0; i < 10; i++)
//         Dp[1][i] = 1;
//     for (int i = 2; i <= N; i++){
//         for (int j = 0; j < 10; j++){
//             if (j == 0)
//                 Dp[i][0] = Dp[i - 1][1] % mod;
//             else if (j == 9)
//                 Dp[i][9] = Dp[i - 1][8] % mod;
//             else
//                 Dp[i][j] = (Dp[i - 1][j - 1] + Dp[i - 1][j + 1]) % mod;
//         }
//     }
//     for (int i = 1; i < 10; i++)
//         sum = (sum + Dp[N][i]) % mod;
//     printf("%d\n", sum%mod);
//     int i = -1;
//     int k = -1;
//     while (i++ < N - 1)
//     {
//         k = -1;
//         printf("row = %d  ", i);
//         while (k++ < 9)
//             printf("%d ", Dp[i][k]);
//         printf("\n");
//     }
// }
