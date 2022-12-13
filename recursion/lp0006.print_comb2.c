#include <unistd.h>
void print_comb2();
void split_digits(int n, char digit[]);
void dfs(int start, int level, int arr[]);

int main()
{
  print_comb2();
  
  return (0);
}

void print_comb2()
{
  int arr[2];
  dfs (0, 0, arr);
}

void split_digits(int n, char digit[])
{
  digit[0] = n / 10 + '0';
  digit[1] = n % 10 + '0';
}

void dfs(int start, int level, int arr[])
{
  char front[2];
  char end[2];

  if (level == 2)
  {
    split_digits(arr[0], front);
    split_digits(arr[1], end);
    write(1, front, 2);
    write(1, " ", 1);
    write(1, end, 2);
    if (arr[0] != 98)
      write(1, ",", 1);
  }
  else
  {
    while (start < 100)
    {
      arr[level] = start;
      dfs(start + 1, level + 1, arr);
      start++;
    }
  }
}