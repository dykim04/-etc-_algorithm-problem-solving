#include <stdio.h>
int col_up(char **board, char *av[], int base)


{
	int		row;
	int		col;
	char	letter;
	int		cnt;

	col = 0;
	while (col < base)
	{
		cnt = 1;
		row = 0;
		letter = board[row][col];
		while (row < base)
		{
			if (letter < board[row][col])
			{
				letter = board[row][col];
				cnt++;
			}
			row++;
		}
		if (cnt + '0' != av[1][2 * col])
			return (0);
		else
			col++;
	}
	return (1);
}

int col_down(char **board, char *av[], int base)
{
	int		row;
	int		col;
	char	letter;
	int		cnt;

	col = 0;
	while (col < base)
	{
		cnt = 1;
		row = base - 1;
		letter = board[row][col];
		while (row >= 0)
		{
			if (letter < board[row][col])
			{
				letter = board[row][col];
				cnt++;
			}
			row--;
		}
		if (cnt + '0' != av[1][2 * base + (2 * col)])
			return (0);
		else
			col++;
	}
	return (1);
}

int row_left(char **board, char *av[], int base)
{
	int		row;
	int		col;
	char	letter;
	int		cnt;

	row = 0;
	while (row < base)
	{
		cnt = 1;
		col = 0;
		letter = board[row][col];
		while (col++ < base - 1)
		{
			if (letter < board[row][col])
			{
				letter = board[row][col];
				cnt++;
			}
		}
		if (cnt + '0' != av[1][4 * base + (2 * row)])
			return (0);
		else
			row++;
	}
	return (1);
}

int row_right(char **board, char *av[], int base)
{
	int		row;
	int		col;
	char	letter;
	int		cnt;

	row = 0;
	while (row < base)
	{
		cnt = 1;
		col = base - 1;
		letter = board[row][col];
		while (col-- > 0)
		{
			if (letter < board[row][col])
			{
				letter = board[row][col];
				cnt++;
			}
		}
		// printf("col = %d, cnt = %d, av = %c\n", col, cnt, av[1][6 * base + (2 * col)]);
		if (cnt + '0' != av[1][6 * base + (2 * row)])
			return (0);
		else
			row++;
	}
	return (1);
}

int is_valid(char **board, char *av[], int base)
{
	int res;

    res = 1;
    res = res * col_up(board, av, base);
    res = res * col_down(board, av, base);
    res = res * row_left(board, av, base);
    res = res * row_right(board, av, base);
	return (res);
}