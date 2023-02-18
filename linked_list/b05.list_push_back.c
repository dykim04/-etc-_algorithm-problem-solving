#include <stdio.h>
#include <stdlib.h>

typedef struct          s_list
{
	struct s_list   *next;
	void            *data;
}                       t_list;

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

void list_push_back(t_list **begin_list, void *data)
{
	t_list *new = (t_list *)malloc(sizeof(t_list));
	t_list *p = *begin_list;
	if (*begin_list == NULL)
	{
		new->data = data;
		new->next = p;
		*begin_list = new;
	}
	else
	{
		while (p->next)
			p = p->next;
		new->data = data;
		new->next = NULL;
		p->next = new;
	}
}

int main(void)
{
	struct s_list *start=NULL;
	char **buff;
	buff = (char **)malloc(sizeof(char *) * 100);
	buff[0] = (char *)malloc(sizeof(char) * 100);
	buff[1] = (char *)malloc(sizeof(char) * 100);
	buff[2] = (char *)malloc(sizeof(char) * 100);
	buff[3] = (char *)malloc(sizeof(char) * 100);
	buff[4] = (char *)malloc(sizeof(char) * 100);
	buff[0] = "hello";
	buff[1] = "world";
	buff[2] = "and";
	buff[3] = "hello";
	buff[4] = "universe!";
	create(&start, buff, 5);
	list_push_front(&start, (void *)"START");
	display(start);
	list_push_back(&start, (void *)"LAST");
	display(start);
}
