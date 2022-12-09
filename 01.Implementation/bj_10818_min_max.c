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
    int min;
    int max;

    i = 0;
    min = arr[0];
    max = arr[0];
    while (i < num)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
        i++;
    }
    printf("%d %d", min, max);
    return (0);
}