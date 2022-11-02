#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char s[10];
    scanf("%s", s);
    printf("%s\n", s);
    printf("%c", s[0]);
    return (0);
}