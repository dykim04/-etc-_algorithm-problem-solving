#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char **create_board(char **board, int base);
void skyscraper_puzzle(char **board, char *av[], int row, int col);
char **initialize_board(char **board, int base);

int strlen(char *str)
{
    int len;

    len = 0;
    while(*str++)
        len++;
    return (len);
}

int valid_str(char *str)
{
    int idx;

    idx = 0;
    while (str[idx])
    {
        if (str[idx] == ' ')
            idx++;
        if (str[idx] >= '1' && str[idx] <= '9')
            idx++;
        else
            return (0);
    }
    return (1);
}

int check_for_error(char *str)
{
    int len;

    len = strlen(str);
    if (!valid_str(str))
        return (0);
    if (len == 31)
        return (1);
    if (len == 39)
        return (1);
    if (len == 47)
        return (1);
    if (len == 55)
        return (1);
    if (len == 63)
        return (1);
    if (len == 71)
        return (1);
    return (0);
}

int find_base(char *str)
{
    int len;

    len = strlen(str);
    if (len == 31)
        return (4);
    if (len == 39)
        return (5);
    if (len == 47)
        return (6);
    if (len == 55)
        return (7);
    if (len == 63)
        return (8);
    if (len == 71)
        return (9);
    else
        return(-1);
}

int main(int ac, char *av[])
{
    int base;
    char **board;

    if (ac == 2)
    {
        if(check_for_error(av[1]))
        {
            base = find_base(av[1]);
            board = (char **)malloc(sizeof(char *) * (base + 1));
            board[base] = NULL;
            create_board(board, base);
            initialize_board(board, base);
            skyscraper_puzzle(board, av, 0, 0);
            if (board[0][0] != 'S')
                write(1, "Error\n", 5);
        }
        else
            write(1, "Error\n", 5);
    }
    return (0);
}