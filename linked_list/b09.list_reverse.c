#include <stdio.h>
#include <stdlib.h>

typedef struct          s_list
{
	struct s_list   *next;
	void            *data;
}                       t_list;

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

int main(void)
{
	struct s_list *start = NULL;
	struct s_list *p = NULL;
	char **buff;
	buff = (char **)malloc(sizeof(char *) * 100);
	*(buff + 0) = create_string("hello");
	*(buff + 1) = create_string("world");
	*(buff + 2) = create_string("and");
	*(buff + 3) = create_string("hello");
	*(buff + 4) = create_string("universe!");
	*(buff + 5) = NULL;
	create(&start, buff, &find_size);
	printf("\n(1)\t"); display(start);
	list_push_front(&start, (void *)"START");
	p = start;
	printf("(2)\t"); display(start);
	start = list_at(start, 0);
	printf("(3)\t"); display(start);
	printf("(4)\t"); display(p);
	list_reverse(&start);
	printf("\n(5)\t"); display(start); printf("\n");
	// free memory
	list_clear(start, &free_fct);
	free_memory(buff, &find_size);
	return (0);
}
