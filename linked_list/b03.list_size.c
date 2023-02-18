#include <stdio.h>
#include <stdlib.h>

typedef struct          s_list
{
        struct s_list   *next;
        void            *data;
}                       t_list;

int list_size(t_list *begin_list)
{
	int size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

void display(struct s_list *start)
{
	while (start)
	{
		printf("%s", (char *)start->data);
		if (start->next)
			printf(" -> ");
		start = start->next;
	}
	printf("\n");
}

t_list *create_elem(struct s_list *start, void *data)
{
	struct s_list *new;
	struct s_list *p;
	new = (struct s_list *)malloc(sizeof(struct s_list));
	p = start;
	while (p->next)
	{
		p = p->next;
	}
	new->next = NULL;
	new->data = data;
	p->next = new;
	p = new;
	return (start);
}

int main(void)
{
	struct s_list *start = NULL;
	start = (struct s_list *)malloc(sizeof(struct s_list) * (1));
	start->next = NULL;
	start->data = (void *)"start";
    create_elem(start, (void *)"hello");
    create_elem(start, (void *)"world");
    create_elem(start, (void *)"hehe");
    create_elem(start, (void *)"123");
    create_elem(start, (void *)"123");
    create_elem(start, (void *)"123");
    create_elem(start, (void *)"123");
    create_elem(start, (void *)"123");
    create_elem(start, (void *)"123");
    create_elem(start, (void *)"123");
    create_elem(start, (void *)"123");
    create_elem(start, (void *)"123");
    create_elem(start, (void *)"123");
    create_elem(start, (void *)"s");
    create_elem(start, (void *)"waffa");
    create_elem(start, (void *)";lknlkn");
    create_elem(start, (void *)"alka");
    create_elem(start, (void *)"oihwef");
    create_elem(start, (void *)"z.x,vcmcxv");
    create_elem(start, (void *)"zvlnvzlvz");
    create_elem(start, (void *)"xzlkvncv");
    create_elem(start, (void *)"sad;lfsdf");
    create_elem(start, (void *)"wepofihwef");
    create_elem(start, (void *)"zcxvoixcv");
	display(start);
	printf("size = [%d]\n", list_size(start));
}
