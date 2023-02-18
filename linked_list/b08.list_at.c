#include <stdio.h>
#include <stdlib.h>

typedef struct          s_list
{
	struct s_list   *next;
	void            *data;
}                       t_list;

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

void create(t_list **start, char **buff, int size)
{
	t_list *new = NULL;
	*start = (t_list *)malloc(sizeof(t_list));
	t_list *p;
	(*start)->data = buff[0];
	(*start)->next = NULL;
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
	create(&start, buff, 5);
	display(start);
	list_push_front(&start, (void *)"START");
	p = start;
	display(start);
	start = list_at(start, 4);
	display(start);
	display(p);
	list_clear(p, &free_fct);
//	display(start);
//	printf("%p\n", start);
//	printf("%p\n", start->next);
//	printf("%p\n", start->next->next);
//	printf("%p\n", start->next->next->next);
//	printf("%p\n", start->next->next->next->next);
//	printf("%p\n", start->next->next->next->next->next);
	for (int i = 0; i < 5; i++)
		free(buff[i]);
	free(buff);
	return (0);
}
