#include "../header/00.base.h"

int ft_strlen(char *str)
{
	int len = 0;
	while(str[len])
		len++;
	return (len);
}

void display_string(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int find_size()
{
	char *file_name = "./dictionary/numbers.dict";
	int r = 1;
	char a;
	int size = 0;
	
	int f = open(file_name, 0);
	if (f == -1)
		return (0);
	while(r)
	{
		r = read(f, &a, 1);
		if (r == -1)
			return (0);
		size++;
	}
	close(f);
	return (size);
}

void string_duplicate(char **buffer, int size)
{
	char *file_name = "./dictionary/numbers.dict";
	int r = 1;
	int idx = 0;
	char a;
	
	int f = open(file_name, 0);
	if (f == -1)
		return ;
	while(r)
	{
		r = read(f, &a, 1);
		if (r == -1)
			return ;
		*(*buffer + idx) = a;
		idx++;
	}
	close(f);
	if (idx != size)
		display_string("Error");
}

void preprocess_dictionary(char ***dict_num, char ***dict_char)
{
	int i;
	int j;
	int k;

	i = j = k = 0;
	while (dict_num[0][i])
	{
		j = k = 0;
		while (dict_num[0][i][j])
		{
			if (dict_num[0][i][j] != ' ')
			{
				dict_num[0][i][k] = dict_num[0][i][j];
				k++;
			}
			j++;
		}
		k = k - 1;
		while (dict_num[0][i][++k])
			dict_num[0][i][k] = 0;
		i++;
	}
	i = j = k = 0;
	while (dict_char[0][i])
	{
		j = k = 0;
		while (dict_char[0][i][j])
		{
			if (dict_char[0][i][j] != ' ')
			{
				dict_char[0][i][k] = dict_char[0][i][j];
				k++;
			}
			j++;
		}
		k = k - 1;
		while (dict_char[0][i][++k])
			dict_char[0][i][k] = 0;
		i++;
	}
}

void create_dictionary(char ***dict_num, char ***dict_char, char **data_ref, int buffer_size)
{
	char **res;	
	int idx = 0;
	int _idx = 0;

	dict_num[0] = (char **)malloc(sizeof(char *) * (buffer_size + 1));
	dict_num[0][buffer_size] = NULL;
	dict_char[0] = (char **)malloc(sizeof(char *) * (buffer_size + 1));
	dict_char[0][buffer_size] = NULL;
	while (idx < buffer_size)
	{
		_idx = -1;
		res = ft_split(data_ref[idx], ":");
		dict_num[0][idx] = (char *)malloc(sizeof(char) * (ft_strlen(res[0]) + 1));
		dict_num[0][idx][ft_strlen(res[0])] = 0;
		while (res[0][++_idx])
			dict_num[0][idx][_idx] = res[0][_idx];
		dict_num[0][idx][_idx] = '\0';
		_idx = -1;
		dict_char[0][idx] = (char *)malloc(sizeof(char) * (ft_strlen(res[1]) + 1));
		dict_char[0][idx][ft_strlen(res[1])] = 0;
		while (res[1][++_idx])
			dict_char[0][idx][_idx] = res[1][_idx];
		dict_char[0][idx][_idx] = '\0';
		idx++;
		free(res[0]);
		free(res[1]);
		free(res);
	}
}

void read_dictionary(char *str)
{
	t_list  *head = NULL;
	char 	**dict_num;
	char 	**dict_char;
	char 	**result;
	char 	*buffer;
	int 	size;
	int 	idx = 0;

	size = find_size();
	buffer = (char *)malloc(sizeof(char) * (size + 1)); 
	buffer[size] = '\0';
	string_duplicate(&buffer, size);
	result = ft_split(buffer, "\n");
    while (result[idx])
	{
        idx++;
	}
	create_dictionary(&dict_num, &dict_char, result, idx);
	preprocess_dictionary(&dict_num, &dict_char);
	head = create_linked_list(dict_num, dict_char);
	find_res(head, str);
	free_lst(head);
	memory_manager(buffer, result, dict_num, dict_char);
}

int main(int ac, char *av[])
{
	// char *test = ft_itoa(0);
	// printf("%s\n", test);
	// free(test);
	if (ac == 2)
	{
		if (is_error(av[1]))
		{
			printf("Error\n");
			return (1);
		}
		read_dictionary(av[1]);
	}
	return (0);
}
