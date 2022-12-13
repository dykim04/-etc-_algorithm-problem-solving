#include <unistd.h>

void non_printable(char c)
{
    unsigned char char_to_hex[2];
    
    if (c / 16 < 10)
        char_to_hex[0] = c / 16 + '0';
    else
        char_to_hex[0] = c / 16 + 87;
    if (c % 16 < 10)
        char_to_hex[1] = c % 16 + '0';
    else
        char_to_hex[1] = c % 16 + 87;
    write(1, "\\", 1);
    write(1, char_to_hex, 2);
}

void putstr_non_printable(char str[])
{
    while (*str)
    {
        if (*str < 32 || *str > 126)
            non_printable(*str);
        else
            write(1, str, 1);
        str++;
    }
}

int main(void)
{
    char str[] = "He\nllo \tW\tor\bld!";
    putstr_non_printable(str);

    return (0);
}