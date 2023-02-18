#include <stdio.h>
#include <stdlib.h>

struct				node
{
	int				data;
	struct node		*next;
}					*start;

void create(int arr[], int size)
{
	int i = 1;
	struct node *p;
	struct node *new;

	start = (struct node *)malloc(sizeof(struct node));
	start->data = arr[0];
	start->next = NULL;
	p = start;
	while (i < size)
	{
		new = (struct node *)malloc(sizeof(struct node));
		new->data = arr[i];
		new->next = NULL;
		p->next = new;
		p = new;
		i++;
	}
}

void display(struct node *start)
{
	while (start)
	{
		printf("[%d]", start->data);
		if (start->next)
			printf(" -> ");
		start = start->next;	
	}
	printf("\n");
}

void sort_list(struct node *start)
{
	struct node *p;
	struct node *q;
	struct node *begin;
	int temp;
	p = start;
	q = start;
	begin = start;
	while (start)
	{
		p = q;
		while (p->next)
		{
			if (p->data > p->next->data)
			{
				temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;
			}
			p = p->next;
		}
		start = start->next;
	}
	start = begin;
}

void sorted_insert(int nbr)
{
	struct node *p;
	struct node *q;
	struct node *new;
	new = (struct node *)malloc(sizeof(struct node));
	new->data = nbr;
	new->next = NULL;
	q = start;
	if (start == NULL)
		start = new;
	else
	{
		while (q && q->data < nbr)
		{
			p = q;
			q = q->next;
		}
		if (p == q)
		{
			new->next = q;
			q = new;
		}
		else
		{
			new->next = p->next;
			p->next = new;
		}
	}
}

int main(void)
{
	int arr[] = {3, 2, 1, 5, 8, 9, 7, 123, 32, 42, 34, 6, 16, 16, 634, 63, 634, 66, 6};
	int size = sizeof(arr) / sizeof(arr[0]);
	create(arr, size);
	sort_list(start);
	sorted_insert(100);	
	display(start);
}
