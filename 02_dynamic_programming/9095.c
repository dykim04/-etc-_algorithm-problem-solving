#include <stdio.h>
int main(void)
{
    int num;
    int i;
    int arr[12];

    num = 0;
    i = 3;
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    while (i++ <= 10)
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];

    scanf("%d", &num);
    int k;
    int idx;
    
    k = 0;
    idx = 0;
    while (k++ < num)
    {
        scanf("%d", &idx);
        printf("%d\n", arr[idx]);
    }
    return (0);
}