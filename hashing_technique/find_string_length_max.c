#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return (len);
}

void create_buffer(char ***buffer)
{
	int i = 0;
	*buffer = (char **)malloc(sizeof(char *) * (1001));
	*((*buffer) + 1000) = NULL;
	while (i < 1000)
	{
		*((*buffer) + i) = (char *)malloc(sizeof(char) * 1001);
		*(*((*buffer) + i) + 1000) = '\0';
		i++;
	}
}

void initialize_buffer(char ***buffer)
{
	int i = 0;
	int k = 0;
	while (i < 1000)
	{
		k = 0;
		while (k < 1000)
		{
			buffer[0][i][k] = '\0';
			k++;
		}
		buffer[0][i][k] = '\0';
		i++;
	}
	buffer[0][i] = 0;
}

void display_buffer(char **buffer)
{
	int i = 0;
	int k = 0;
	while (buffer[i])
	{
		k = 0;
		while (buffer[i][k])
		{
			write(1, &buffer[i][k], 1);
			k++;
		}
		if (strlen(buffer[i]))
			write(1, "\n", 1);
		i++;
	}
}

void free_buffer(char **buffer)
{
	int i = 0;
	while (i < 1001)
	{
		free(buffer[i]);
		i++;
	}
	free(buffer); 
}

int strcmp(char *s1, char *s2)
{
	int idx = 0;
	while (s1[idx] && (s1[idx] == s2[idx]))
		idx++;
	return (s1[idx] - s2[idx]);
}

char *create_candidate(char *str, int offset, int last)
{
	char *candidate;
	int i = 0;
	int size = last - offset + 1;
	
	candidate = (char *)malloc(sizeof(char) * (size + 1));
	candidate[size] = '\0';
	while (i < size)
	{
		candidate[i] = str[offset];
		i++;
		offset++;
	}
	candidate[i] = '\0';
	return (candidate);
}

int	strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (index < n)
	{
		if (s1[index] != s2[index] || s1[index] == '\0')
			return (s1[index] - s2[index]);
		index++;
	}
	return (0);
}

int is_valid(char *candidate, char *av[])
{
	int offset = 2;
	int i = 0;
	int size = 0;
	int flag[1000] = {1, 1, 0, };
	int judge = 0;

	while (av[size])
		size++;
	while (av[offset])
	{
		i = 0;
		while (i < strlen(av[offset]))
		{
			if (strncmp(candidate, (av[offset] + i), strlen(candidate)) == 0)
				flag[offset] = 1;
			i++;
		}
		offset++;
	}
	while (flag[judge])
		judge++;
	if (judge == offset)
		return (1);
	return (0);
}

void str_cat_cpy(char ***buff, char *candidate)
{
	int i = 0;
	int k = 0;
	int len = strlen(candidate);
	while (buff[0][i][0])
		i++;
	while(k < len)
	{
		buff[0][i][k] = candidate[k];
		k++;
	}
}

void possibilities(char **buffer, char *av[])
{
	int len = 0;
	int offset = 0;
	int last = 0;
	char *str = av[1];
	char *candidate;

	while (av[len])
		len++;
	while (str[offset])
	{
		last = offset;
		while (last < strlen(str))
		{
			candidate = create_candidate(str, offset, last);
			if (is_valid(candidate, av))
				str_cat_cpy(&buffer, candidate);
			free(candidate);
			last++;
		}
		offset++;
	}
}

void putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void display_res(char **buffer)
{
	int dat[1000] = {0};
	int size = 0;
	int i = 0;
	int max = 0;
	
	while (buffer[size][0])
		size++;
	while (i < size)
	{
		dat[i] = strlen(buffer[i]);
		i++;
	}
	
	i = 0;
	while (dat[i])
	{
		if (dat[i] > max)
			max = dat[i];
		i++;
	}

	i = 0;
	while (dat[i])
	{
		if (dat[i] == max)
			break;
		i++;
	}
	putstr(buffer[i]);
}

int main(int ac, char *av[])
{
	char **buffer; //save the qualified candidates
	create_buffer(&buffer);
	initialize_buffer(&buffer);
	//display_buffer(buffer);
	if (ac != 1)
	{
		// create buffer that contains all possible candidates
		possibilities(buffer, av);

		// display the only candidate that meets the following two conditions
		// 1. the longest string
		// 2. the earliest (most left)
		// all in all -> display the res / answer
		display_res(buffer);
	}
	free_buffer(buffer);
	write(1, "\n", 1);
	return (0);
}
