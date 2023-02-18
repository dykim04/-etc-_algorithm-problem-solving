#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int dat1[10000] = {0};
int dat2[10000] = {0};
int idx = 0;

void display_arr(int arr[], int len)
{
	for (int i = 0; i < len; i++)
		printf("%d %d\n", i, arr[i]);
}

int is_seen(int arr[], int nb, int i)
{
	if (i == 0)
		return (0);
	i = i - 1;
	while (i >= 0)
	{
		if (arr[i] == nb)
			return (1);
		i--;
	}
	return (0);
}
void putnbr(int nbr)
{
	int rem;

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

void putchar(int nb)
{
	write(1, &nb, 1);
}

int strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return (len);
}

void call(int arr[], int nb, int i, int len)
{
	int res = 0;
	int _i = i;
	while (i < len)
	{
		if (arr[i] == nb)
			res++;
		i++;
	}
	dat1[idx] = res;
	dat2[idx] = arr[_i];
	idx++;
	//putnbr(res);
	//putchar(arr[_i]);
}

void couand_call(int arr[], int len)
{
	int i = -1;
	while (++i < len)
	{
		if (is_seen(arr, arr[i], i))
			continue ;
		call(arr, arr[i], i, len);
	}
}

void coualpha(char *str)
{
	int arr[10000] = {0};
	int len = 0;
	int i = 0;
	while (str[len])
		len++;
	while (i < len)
	{
		arr[i] = str[i];
		i++;
	}
	couand_call(arr, len);
}

char *small(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

int find_len(char *str)
{
	int i = 0;
	int len = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			len++;
		i++;
	}
	return (len);
}

void strdup(char *buff, char *str)
{
	int i = 0;
	int j = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			buff[j] = str[i];
			j++;
		}
		i++;
	}
	buff[j] = '\0';
}

char *create_string(char *str, char *(*small)())
{
	int len = 0;
	char *buff;
	small(str);
	len = find_len(str);
	buff = (char *)malloc(sizeof(char) * (len + 1));
	strdup(buff, str);
	buff[len] = '\0';
	return (buff);
}

void display_res(int dat1[], int dat2[])
{
	int len = 0;
	int idx = 0;
	while (dat1[len])
		len++;
	while (idx < len)
	{
		putnbr(dat1[idx]);
		putchar(dat2[idx]);
		if (idx != len-1)
			write(1, ", ", 2);
		idx++;
	}
}


int main(int ac, char *av[])
{
	char *buff;
	if (ac == 2)
	{
		buff = create_string(av[1], &small);
		coualpha(buff);
		display_res(dat1, dat2);
		free(buff);
	}
	write(1, "\n", 1);
	return (0);
}
