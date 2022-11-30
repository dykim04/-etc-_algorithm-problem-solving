// #include <stdio.h>
// int main(void)
// {
//     int num;
//     int i;
//     num = 0;
//     i = -1;
//     scanf("%d", &num);
//     int arr[num];
//     while (++i < num)
//         scanf("%d", &arr[i]);
//     int k;
//     int j;
//     int temp;

//     k = -1;
//     while (++k < num)
//     {
//         j = -1;
//         while (++j < num)
//         {
//             temp = arr[j];
//             if (arr[j] > arr[j + 1])
//             {
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }

//     k = -1;
//     while (++k < num)
//         printf("%d\n", arr[k]);
//     return (0);
// }

#include <stdio.h>
int main(void)
{
    int num;
    int i;
    num = 0;
    i = -1;
    scanf("%d", &num);
    int arr[num];
    while (++i < num)
        scanf("%d", &arr[i]);
    int k;
    int j;
    int temp;

    k = -1;
    while (++k < num)
    {
        j = -1;
        while (++j < num)
        {
            temp = arr[j];
            if (arr[j] > arr[j + 1])
            {
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    k = -1;
    while (++k < num)
        printf("%d\n", arr[k]);
    return (0);
}