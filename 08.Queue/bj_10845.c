#include <stdio.h>
#include <string.h>
void    push(int num, int *arr, int cnt)
{
    arr[cnt] = num;
}
void    pop(int *arr, int cnt)
{
    if (cnt >= 1)
    {
        if (arr[cnt - 1] == '\0')
            printf("-1\n");
        else 
            printf("%d\n", arr[0]);
    }
    else
        printf("-1\n");
    int i;
    int k;

    i = 0;
    k = 0;
    while (arr[i] || arr[k + 1])
    {
        arr[i] = arr[k + 1];
        i++;
        k++;
    }
    arr[cnt - 1] = '\0';
}
void    size(int *arr)
{
    int k;
    
    k = 0;
    while (arr[k] != '\0')
        k++;
    printf("%d\n", k);
    // k = -1;
    // while (arr[++k])
    // printf("%d", k);
}
void    empty(int *arr)
{
    int k;
    
    k = 0;
    while (arr[k] != '\0')
        k++;
    if (k == 0)
        printf("1\n");
    else
        printf("0\n");
}
void    front(int *arr)
{
    int k;

    k = 0;
    if (arr[k] != '\0')
        printf("%d\n", arr[0]);
    else
        printf("-1\n");
}
void    back(int *arr)
{
    int k;
    
    k = 0;
    while (arr[k] != '\0')
        k++;
    if (k == 0)
        printf("-1\n");
    else
        printf("%d\n", arr[k - 1]);
}
int main(void)   
{
    int     arr[10001];
    char    order[10001];
    int     i;
    int     N;
    int     num;
    int     cnt;

    i = 0;
    N = 0;
    cnt = 0;
    scanf("%d", &N);
    while (i < N)
    {
        scanf("%s", order);
        // printf("order = %s\n", order);
        if (strcmp("push", order) == 0)
        {
            scanf("%d", &num);
            // printf("num = %d\n", num);
            push(num, arr, cnt);
            cnt++;
        }
        if (strcmp("pop", order) == 0)
        {
            pop(arr, cnt);
            if (cnt >= 1)
                cnt--;
        }
        if (strcmp("size", order) == 0)
            size(arr);
        if (strcmp("empty", order) == 0)
            empty(arr);
        if (strcmp("front", order) == 0)
            front(arr);
        if (strcmp("back", order) == 0)
            back(arr);
        i++;
        // printf("N = %d i = %d\n", N, i);
    }
    // int check;
    // check = 0;
    // while (arr[check])
    // {
    //     printf("%d", arr[check]);
    //     check++;
    // }
    return (0);
}
// 15
// push 1
// push 2
// front    1
// back     2
// size     2
// empty    0
// pop      1
// pop      2
// pop      -1
// size     0
// empty    1
// pop      -1
// push 3
// empty    0
// front    3

// 1 2     3