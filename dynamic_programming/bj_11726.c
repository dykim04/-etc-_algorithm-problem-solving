#include <stdio.h>
int main(void)
{
    int num;
    int i;
    int arr[1001];
    
    num = 0;
    i = 1;
    arr[0] = 1;
    arr[1] = 1;
    scanf("%d", &num);
    while (i++ < num)
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
    if (num == 0 || num == 1)
        printf("%d\n", arr[num]);
    else
        printf("%d\n", arr[i - 1] % 10007);
    printf("-------------------\n");
    int k = -1;
    while(k++ < num)
        printf("arr[%d] = %d\n", k, arr[k]);
    return (0);
}

// #include <stdio.h>
// int main(void)
// {
//     int num;
//     int i;
//     int arr[1001];
    
//     num = 0;
//     i = 2;
//     arr[0] = 1;
//     arr[1] = 1;
//     arr[2] = 2;
//     scanf("%d", &num);
//     if (num == 0 || num == 1)
//         printf("1\n");
//     if (num == 2)
//         printf("2\n");
//     while (i++ < num)
//     {
//         arr[i] = arr[i - 1] + arr[i - 2];
//         printf("%d\n", arr[i]);
//     }
//     printf("-------------------\n");
//     int k = -1;
//     while(k++ < num)
//         printf("arr[%d] = %d\n", k, arr[k]);
//     return (0);
// }