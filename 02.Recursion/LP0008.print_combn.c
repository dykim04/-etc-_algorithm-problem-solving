#include <unistd.h>
void print_combn(int n);
void dfs(int start, int level, int n, char arr[]);

int main()
{
    print_combn(3);

    return (0);
}

void print_combn(int n)
{
    char arr[10];

    dfs(0, 0, n, arr);
}

void dfs(int start, int level, int n, char arr[])
{
    if (level == n)
    {
        write(1, arr, n);
        if (arr[0] - '0' != 10 - n)
            write(1, ", ", 2);
    }
    else
    {
        while (start < 10)
        {
            arr[level] = start + '0';
            dfs (start + 1, level + 1, n, arr);
            start++;
        }
    }
}