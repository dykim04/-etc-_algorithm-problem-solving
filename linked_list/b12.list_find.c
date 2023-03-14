#include <stdio.h>
#include <stdlib.h>

typedef struct          s_list
{
	struct s_list   *next;
	void            *data;
}                       t_list;

t_list *list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list *first;

	first = begin_list;
	while (begin_list)
	{
		if (cmp(begin_list->data, data_ref) == 0)
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (first);
}

t_list *list_at(t_list *begin_list, unsigned int nbr)
{
	t_list *offset;
	offset = begin_list; 
	unsigned int len = 0;
	unsigned int idx = 0;
	while (offset)
	{
		len++;
		offset = offset->next;
	}
	if (nbr >= len)
		return (NULL);
	offset = begin_list;
	while (idx < nbr)
	{
		offset = offset->next;
		idx++;
	}
	return (offset);
}

void display(struct s_list *start)
{
	while (start)
	{
		printf("%s", (char *)start->data);
		if (start->next)
				printf(" -> ");
		start = (start)->next;
	}
	printf("\n");
}

void list_push_front(t_list **begin_list, void *data)
{
	t_list *new = (t_list *)malloc(sizeof(t_list));
	t_list *p = *begin_list;
	if (*begin_list)
	{
		new->data = data;
		new->next = p;
		*begin_list = new;
	}
	else
	{
		*begin_list = (t_list *)malloc(sizeof(t_list));
		(*begin_list)->data = data;
		(*begin_list)->next = NULL;
	}
}

void create(t_list **start, char **buff, int (*f)(char **))
{
	t_list *new = NULL;
	*start = (t_list *)malloc(sizeof(t_list));
	t_list *p;
	(*start)->data = buff[0];
	(*start)->next = NULL;
	int size = (f)(buff);
	p = (*start);
	for (int i = 1; i < size; i++)
	{
		new = (t_list *)malloc(sizeof(t_list));
		new->data = buff[i];
		new->next = NULL;
		p->next = new;
		p = new;
	}
}

void free_fct(void *fct)
{
	free((struct s_list *)fct);
}

void list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	struct s_list *p;
	while (begin_list)
	{
		p = begin_list;
		begin_list = begin_list->next;
		free_fct(p);
	}
}

char *create_string(char *str)
{
	int len = 0;
	int idx = 0;
	while (str[len])
		len++;
	char *strdup;
	strdup = (char *)malloc(sizeof(char) * (len + 1));
	strdup[len] = '\0';
	while (idx < len)
	{
		strdup[idx] = str[idx];
		idx++;
	}
	strdup[idx] = '\0';
	return (strdup);
}

int find_size(char **buff)
{
	int size = 0;
	while (*buff++)
	{
		size++;
	}
	return (size);
}

void free_memory(char **buff, int (*f)(char **))
{
	for (int i = 0; i < f(buff); i++)
		free(buff[i]);
	free(buff);
}

void display_addr(t_list *begin_list)
{
	while (begin_list)
	{
		printf("\t %p\n", begin_list);
		begin_list = begin_list->next;
	}
}

void list_reverse(t_list **begin_list)
{
	t_list *last = *begin_list;
	t_list *middle = NULL;
	t_list *first = NULL;
	
	while (last)
	{
		first = middle;
		middle = last;
		last = last->next;
		middle->next = first;
	}

	*begin_list = middle;
	printf("\naddr:\n"); display_addr(*begin_list); printf("\n");
	display_addr(*begin_list);
}

void display_data(void *data)
{
	printf("\t\to/p list_foreach -> [%s]\n", (char *)data);
}

void list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *p;
	p = begin_list;

	printf("result of list_foreach\n");
	while (p)
	{
		f(p->data);
		p = p->next;
	}
}

int strcmp(char *s1, char *s2)
{
	int idx = 0;
	while (s1[idx] && s1[idx] == s2[idx])
		idx++;
	return (s1[idx] - s2[idx]);
}

void list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)())
{
	printf("\nresult of list_foreach_if\n");
	while (begin_list)
	{
		if (cmp((char *)begin_list->data, (char *)data_ref) == 0)
			f(begin_list->data);
		begin_list = begin_list->next;
	}
	printf("\n");
}

int main(void)
{
	struct s_list *start = NULL;
	struct s_list *first = NULL;
	struct s_list *test = NULL;

	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	char **buff;
	buff = (char **)malloc(sizeof(char *) * 100);
	*(buff + 0) = create_string("hello");
	*(buff + 1) = create_string("world");
	*(buff + 2) = create_string("and");
*(buff + 3) = create_string("hello");
	*(buff + 4) = create_string("universe!");
	*(buff + 5) = NULL;
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	create(&start, buff, &find_size);
	printf("\n(1)\t"); display(start);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	list_push_front(&start, (void *)"START");
	first = start;
	printf("(2)\t"); display(start);
	start = list_at(start, 3);
	printf("(3)\t"); display(start);
	printf("(4)\t"); display(first);
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	list_reverse(&start);
	printf("\n(5)\t"); display(start); printf("\n");

	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	list_reverse(&start);
	printf("\n(6)\t"); display(start); printf("\n");

	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	list_foreach(start, &display_data);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	list_foreach_if(first, &display_data, (void *)"hello", &strcmp);
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	test = list_find(first, (void *)"and", &strcmp);
	display(test);
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////// free memory ///////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	list_clear(first, &free_fct); //////////////////////////////////////////////////////////////////////////
	free_memory(buff, &find_size); /////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	return (0);
}
