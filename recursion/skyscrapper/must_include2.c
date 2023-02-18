#include <stdio.h>

void display_board(char **board, int base);
int	find_base(char *str);
int col_up_cnt(char **board, char *av[], int row, int col)
{
	char	letter;
	int		cnt;
	int		row_idx;
	
	letter = board[0][col];
	cnt = 1;
	row_idx = row;	
	row = 0;
	while (row < row_idx + 1)
	{
		if (board[row][col] > letter)
		{
			letter = board[row][col];
			cnt++;
		}
		row++;
	}
	// printf("col_up\t\tcnt = %d, av = %c\n", cnt, av[1][2 * col]);
	if (cnt + '0' > av[1][2 * col])
		return (0);
	return (1);
}


int row_left_cnt(char **board, char *av[], int row, int col)
{
	char	letter;
	int		cnt;
	int 	col_idx;

	letter = board[row][0];
	cnt = 1;
	col_idx = col;
	col = 1;
	while (col < col_idx + 1)
	{
		if (board[row][col] > letter)
		{
			letter = board[row][col];
			cnt++;
		}
		col++;
	}
	// printf("row_left\tcnt = %d, av = %c\n", cnt, av[1][4 * base + (2 * row)]);
	if (cnt + '0' > av[1][4 * find_base(av[1]) + (2 * row)])
		return (0);
	return (1);
}

int col_down_cnt(char **board, char *av[], int row, int col)
{
	char	letter;
	int		cnt;
	
	letter = board[row][col];
	cnt = 1;
	while (row >= 0)
	{
		if (board[row][col] > letter)
		{
			letter = board[row][col];
			cnt++;
		}
		row--;
	}
	// printf("col_down \tcnt = %d, av = %c\n", cnt, av[1][(2 * base) + (2 * col)]);
	if (cnt + '0' != av[1][(2 * find_base(av[1])) + (2 * col)])
		return (0);
	return (1);
}

int row_right_cnt(char **board, char *av[], int row, int col)
{
	char	letter;
	int		cnt;

	letter = board[row][col];
	cnt = 1;
	while (col >= 0)
	{
		if (board[row][col] > letter)
		{
			letter = board[row][col];
			cnt++;
		}
		col--;
	}
	// printf("rowright\tcnt = %d, av = %c\n", cnt, av[1][6 * base + (2 * row)]);
	if (cnt + '0' != av[1][6 * find_base(av[1]) + (2 * row)])
		return (0);
	return (1);
}

#include <stdio.h>
int	must_include2(char **board, char *av[], int row, int col)
{
	// printf("---------------------------------------------\n");
    // printf("(%d, %d)\n", row, col);
	// display_board(board, base);
	int go;

	go = 1;
	go = go * col_up_cnt(board, av, row, col);
	go = go * row_left_cnt(board, av, row, col);
	if (row == find_base(av[1]) - 1)
		go = go * col_down_cnt(board, av, row, col);
	if (col == find_base(av[1]) - 1)
		go = go * row_right_cnt(board, av, row, col);
	return (go);
}