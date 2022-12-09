#include <unistd.h>

int main()
{
	print_comb();
}

void	print_comb(void)
{
	char	arr[3];

	dfs(0, 0, arr);
}

void	dfs(int start, int level, char comb[])
{
	if (level == 3)
	{
		write(1, comb, 3);
		if (comb[0] - '0' != 7)
		{
			write(1, ", ", 2);
		}
	}
	else
	{
		while (start < 10)
		{
			comb[level] = start + '0';
			dfs(start + 1, level + 1, comb);
			start++;
		}
	}
}

