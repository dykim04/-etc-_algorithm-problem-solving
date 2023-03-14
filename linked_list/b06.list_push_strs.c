#include <stdio.h>
#include <stdlib.h>

typedef struct          s_list
{
	struct s_list   *next;
	void            *data;
}                       t_list;

t_list *list_push_strs(int size, char **strs)
{
	struct s_list *new = NULL;
	struct s_list *p = NULL;
	struct s_list *start = NULL;
	new = (t_list *)malloc(sizeof(t_list));
	new->data = (void *)strs[0];
	new->next = NULL;
	start = new;
	p = new;
	for (int i = 1; i < size; i++)
	{
		new = (t_list *)malloc(sizeof(t_list));
		new->data = (void *)strs[i];
		new->next = NULL;
		p->next = new;
		p = new;
	}
	return (start);
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

int main(void)
{
	struct s_list *start = NULL;
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
	start = list_push_strs(5, buff);
	display(start);
}
