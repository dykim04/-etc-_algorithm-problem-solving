#include <unistd.h>
#include <stdlib.h>

int strcmp(char *s1, char *s2)
{
	int idx = 0;
	while (s1[idx] && (s1[idx] == s2[idx]))
		idx++;
	return (s1[idx] - s2[idx]);
}

int is_seen(char *str, char **av, int i)
{
	if (i == 0)
		return (1);
	i = i - 1;
	while (i >= 0)
	{
		if (strcmp(av[i], str) == 0)
			return (0);
		i--;
	}
	return (1);
}

void putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void putnbr(unsigned int nbr)
{
	unsigned int rem;

	rem = 0;
	if (nbr < 10)
	{
		rem = (nbr % 10) + '0';
		write(1, &rem, 1);
	}
	else
	{
		rem = (nbr % 10) + '0';
		putnbr(nbr / 10);
		write(1, &rem, 1);
	}
}

void count_call_elem(char *str, char **av, unsigned int len)
{
	unsigned int i = 0;
	unsigned int res = 0;
	while (i < len)
	{
		if (strcmp(str, av[i]) == 0)
			res++;
		i++;
	}
	write(1, "[", 1);
	putstr(str);
	write(1, "]", 1);
	write(1, " -> ", 4);
	putnbr(res);
	write(1, "\n", 1);
}

int main(int ac, char *av[])
{
	if (ac != 1)
	{
		unsigned int len = 0;
		while (av[len])
			len++;
		unsigned int i = 0;
		while (++i < len)
		{
			if (!is_seen(av[i], av, i))
				continue ;
			count_call_elem(av[i], av, len);
		}
	}
	return (0);
}
