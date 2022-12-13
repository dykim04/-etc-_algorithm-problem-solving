#include <stdio.h>
int main(void)
{
    int num;
    int i;

    num = 0;
    i = 0;
    scanf("%d", &num);
    int arr[num + 1];
    while (i < num)
    {
        scanf("%d", &arr[i]);
        i++;
    }
    arr[i] = '\0';
    int idx;
    int temp;

    idx = 0;
    i = 0;
    temp = 0;
    // printf("%d", arr[0]);
    // printf("%d", arr[1]);
    // printf("%d", arr[2]);
    // printf("%d\n", arr[3]);
    while (i < num - 1)
    {
        idx = 0;
        while (idx < num -1)
        {
            if (arr[idx] > arr[idx + 1])
            {
                temp = arr[idx];
                arr[idx] = arr[idx + 1];
                arr[idx + 1] = temp;
            }
            idx++;
        } 
        i++;
    }
    // printf("%d", arr[0]);
    // printf("%d", arr[1]);
    // printf("%d", arr[2]);
    // printf("%d\n", arr[3]);
    // i = 0;
    // while (i < num)
    // {
    //     printf("%d", arr[i]);
    //     i++;
    // }
    // printf("%d", arr[i]);
    if (num == 1)
        printf("%d", arr[0]);
    else
        printf("%d %d", arr[0], arr[num - 1]);
    return (0);
}