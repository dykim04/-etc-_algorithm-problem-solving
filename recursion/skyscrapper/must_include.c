int	must_include(char **board, int row, int col)
{
	int	row_idx;
	int	col_idx;

	row_idx = 0;
	col_idx = 0;
	while (row_idx < row)
	{
		if (board[row][col] == board[row_idx][col])
			return (0);
		row_idx++;
	}
	while (col_idx < col)
	{
		if (board[row][col] == board[row][col_idx])
			return (0);
		col_idx++;
	}
	return (1);
}