#include <stdlib.h>

char **create_board(char **board, int base)
{
    int i;

    i = 0;
    while (i < base)
    {
        board[i] = (char *)malloc(sizeof(char) * (base + 1));
        board[i][base] = '\0';
        i++;
    }
    return (board);
}

char **initialize_board(char **board, int base)
{
    int row;
    int col;

    row = 0;
    col = 0;
    while (row < base)
    {
        col = 0;
        while (col < base)
        {
            board[row][col] = '0';
            col++;
        }
        row++;
    }
    return (board);
}