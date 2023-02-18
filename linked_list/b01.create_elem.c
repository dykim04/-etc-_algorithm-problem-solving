#include <stdio.h>
#include <stdlib.h>

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

t_list *create_elem(void *data)
{
	struct s_list *new;
	new = (struct s_list *)malloc(sizeof(struct s_list));
	new->next = NULL;
	new->data = data;
	return (new);
}

void display(struct s_list *node)
{
	while (node)
	{
		printf("%s\n", (char *)node->data);
		node = node->next;
	}
}

int main(void)
{
	struct s_list *start;
	start = create_elem((void *)"hello world!");
	display(start);
	return (0);
}
