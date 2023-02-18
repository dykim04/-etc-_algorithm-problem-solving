/*  • Create a function that displays all possible placements of the ten queens on a
	  chessboard which would contain ten columns and ten lines, without them being
	  able to reach each other in a single move, and returns the number of possibilities.
	
	• Recursivity is required to solve this problem.
	
	• Here’s how it’ll be displayed :
		$>./a.out | cat -e
		0257948136$
		0258693147$
		...
		4605713829$
		4609582731$
		...
		9742051863$
		$>
	
	• The sequence goes from left to right. The first digit represents the first Queen’s
	  position in the first column (the index starting from 0). 
	  The Nth digit represents the Nth Queen’s position in the Nth column.
	
	• The return value must be the total number of displayed solutions. 				*/

#include <unistd.h>
#include <stdio.h>

int	is_valid(char ten_queens[], int col_level, char start_index)
{
	int		col_index;
	int		x_axis;
	int		y_axis;

	col_index = 0;
	while (col_index < col_level)
	{
		x_axis = col_level - col_index;
		y_axis = ten_queens[col_index] - start_index;
		if (y_axis == 0)
			return (0);
		if ((x_axis == y_axis) || (x_axis == -y_axis))
			return (0);
		col_index++;
	}
	return (1);
}

int	dfs(int col_level, char ten_queens[])
{
	int	start;
	int	result;

	start = 0;
	result = 0;
	if (col_level == 10)
	{
		write(1, ten_queens, 10);
		write(1, "\n", 1);
		return (1);
	}
	while (start < 10)
	{
		if (is_valid(ten_queens, col_level, start + '0') == 1)
		{
			ten_queens[col_level] = start + '0';
			result = result + dfs(col_level + 1, ten_queens);
		}
		start++;
	}
	return (result);
}

int	ten_queens_puzzle(void)
{
	char	ten_queens[10];

	return (dfs(0, ten_queens));
}

int	main()
{
	ten_queens_puzzle();
	printf("%d", ten_queens_puzzle());
	
	return (0);
}
