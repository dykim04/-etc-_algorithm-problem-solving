#include <stdio.h>
int main(void)
{
    int arr[1000001];
    int num;
    int i;
    
    arr[0] = 0;
    arr[1] = 0;
    num = 0;
    i = 2;
    scanf("%d", &num);
    if (num == 1)
        printf("%d", arr[1]);
    else if (num >= 2 && num <= 1000000)
    {
        while (i <= num)
        {
            arr[i] = arr[i - 1] + 1;
            if (i % 2 == 0)
            {
                if (arr[i] > arr[i / 2] + 1)
                    arr[i] = arr[i / 2] + 1;
            }
            if (i % 3 == 0)
            {
                if (arr[i] > arr[i / 3] + 1)
                    arr[i] = arr[i / 3] + 1;
            }
            // printf("%d\n", i);
            i++;
        }
        // i = 0;
        // while (i++ < num)
        //     printf("arr[%d] = %d\n", i, arr[i]);
        // printf("%d", arr[num]);
        printf("%d", arr[num]);
    }
    // else
    //     printf("Error, number must be between 1 ~ 1000000");
    return (0);
}