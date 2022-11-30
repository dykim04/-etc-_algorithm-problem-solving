#include <stdio.h>
#include <string.h>
void push (int num, int *arr, int cnt);
void pop (int *arr, int cnt);
void size (int *arr);
void empty (int *arr);
void top (int *arr);
int main(void)
{
    int arr[100001];
    char order[6];
    int i;
    int N;
    int num;
    int cnt;

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
        if (strcmp("top", order) == 0)
            top(arr);
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
void push (int num, int *arr, int cnt)
{
    arr[cnt] = num;
}
void pop (int *arr, int cnt)
{
    if (cnt >= 1)
    {
        if (arr[cnt - 1] == '\0')
            printf("-1\n");
        else 
            printf("%d\n", arr[cnt - 1]);
    }
    else
        printf("-1\n");
    arr[cnt - 1] = '\0';
}
void size (int *arr)
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
void empty (int *arr)
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
void top (int *arr)
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

// 14
// push 1
// push 2
// top
// size
// empty
// pop
// pop
// pop
// size
// empty
// pop
// push 3
// empty
// top

// 2
// 2
// 0
// 2
// 1
// -1
// 0
// 1
// -1
// 0
// 3