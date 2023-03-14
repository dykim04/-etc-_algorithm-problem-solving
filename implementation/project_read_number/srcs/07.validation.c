#include "../header/00.base.h"

int is_error(char *str)
{
    if (ft_strlen(str) >= 40)
        return (1);
    return (0);
}