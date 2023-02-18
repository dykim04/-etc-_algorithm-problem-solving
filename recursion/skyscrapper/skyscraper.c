#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int is_valid(char **board, char *av[], int base);
int	must_include(char **board, int row, int col);
int	must_include2(char **board, char *av[], int row, int col);
int row_right_cnt(char **board, char *av[], int row, int col);
int find_base(char *str);

void display_board(char **board, int base)
{
    int row = 0;
    int col = 0;
    while (row < base)
    {
        col = 0;
        while (col < base)
        {
            printf("%c", board[row][col]);
            printf(" ");
            col++;
        }
        printf("\n");
        row++;
    }
    board[0][0] = 'S';
}
 
void skyscraper_puzzle(char **board, char *av[], int row, int col)
{
    if (board[0][0] == 'S')
        return ;
    if (row == find_base(av[1]))
    {
        if (is_valid(board, av, find_base(av[1])))
            display_board(board, find_base(av[1]));
        return ;
    }
    else
    {         
        board[row][col] = '0';
        while (board[row][col] < find_base(av[1]) + '0')
        {
            board[row][col] = board[row][col] + 1;
            if (!must_include(board, row, col))
                continue;
            if (!must_include2(board, av, row, col))
                continue;
            if (col == find_base(av[1]) - 1)
                skyscraper_puzzle(board, av, row + 1, 0);
            else    
                skyscraper_puzzle(board, av, row, col + 1);
        }
    }
}