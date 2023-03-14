#include "../header/00.base.h"

int	len(long nb)
{
	int	len = 0;
	if (nb == 0)
		return (1);


	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return(len);
}
char	*ft_itoa(int nb)
{
	char	*str;
	long	n;
	int	i;

	n = nb;
	i = len(n);
	if(!(str = (char *)malloc(i + 1)))
		return(0);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return(str);
	}
	if(n < 0)
	{
		str[0] = '-';
		str[1] = 0;
		n *= -1;
	}
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n /= 10;
		i--;
	}
	return (str);
}

int ft_atoi(char *str)
{
    int idx;
    int sign;
    int res;

    idx = 0;
    sign = 1;
    res = 0;
    while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == 32)
    {
        idx++;
    }
    while (str[idx] == '+' || str[idx] == '-')
    {
        if (str[idx] == '-')
        {
            sign = sign * (-1);
        }
        idx++;
    }
    while (str[idx] >= '0' && str[idx] <= '9')
    {
        res = (res * 10) + str[idx] - '0';
        idx++;
    }
    return (res * sign);
}

int ft_nbrcmp(int nb1, int nb2)
{
	if (((nb1 % nb2) == 0) && ((nb1 / nb2) == 1))
		return (0);
	return (1);
}