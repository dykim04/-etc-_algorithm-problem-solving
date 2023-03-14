#include <stdio.h>
#include <stdlib.h>

typedef struct          s_list
{
	struct s_list   *next;
	void            *data;
}                       t_list;

void sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list *new;
	t_list *last;
	t_list *ptr;
	int flag = 1;

	ptr = *begin_list;
	last = *begin_list;
	new = (t_list *)malloc(sizeof(t_list));
	new->data = create_string((char *)data);
	new->next = NULL;
	if (*begin_list == NULL)
	{
		*begin_list = new;
		return ;
	}
	while (last)
	{
		if (cmp((char *)last->data, (char *)data) >= 0 && flag)
		{
			new->next = last;
			break ;
		}
		else if(cmp((char *)last->data, (char *)data) >= 0)
			break;
		flag = 0;
		ptr = last;
		last = last->next;
		//free_fct(ptr->data);
		//free_fct((void *)ptr);
	}
	if (flag)
	{
		*begin_list = new;
		return ;
	}
	ptr->next = new;
	new->next = last;
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

void list_clear(t_list *begin_list, void (*free_fct)(void *))
{	
	struct s_list *p;
	while (begin_list)
	{
		p = begin_list;
		begin_list = begin_list->next;
		free_fct(p->data);
		free_fct((void *)p);
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
	printf("\n");
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
	printf("\t\t\t\t (o/p list_foreach -> [%s])\n", (char *)data);
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

void free_fct(void *fct)
{
	free(fct);
}

void list_push_front(t_list **begin_list, void *data)
{
	t_list *p;
	if (*begin_list)
	{
		p = *begin_list;
		t_list *new = (t_list *)malloc(sizeof(t_list));
		new->data = (void *)create_string((char *)data);
		new->next = *begin_list;
		p = new;
		*begin_list = p;
	}
	else
	{
		*begin_list = (t_list *)malloc(sizeof(t_list));
		(*begin_list)->data = data;
		(*begin_list)->next = NULL;
	}
}

void list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list *first;
	t_list *last;
	
	first = last = *begin_list;
	if (cmp((char *)(last)->data, (char *)data_ref) == 0)
	{
		first = (*begin_list)->next;
		*begin_list = first;
		free_fct(last->data);
		free_fct((void *)last);
		return ;
	}
	else
	{
		while (last)
		{
			if (cmp((char *)(last)->data, (char *)data_ref) == 0)
			{
				first->next = last->next;
				free_fct(last->data);
				free_fct((void *)last);
				last = first;
			}
			first = last;
			last = last->next;
		}
	}
}

void list_merge(t_list **begin_list, t_list *begin_list2)
{
	t_list *first;

	first = *begin_list;
	while ((*begin_list)->next)
		*begin_list = (*begin_list)->next;
	while (begin_list2)
	{
		(*begin_list)->next = begin_list2;
		begin_list2 = begin_list2->next;
		*begin_list = (*begin_list)->next;
	}
	*begin_list = first;
}

void list_sort(t_list **begin_list, int (*cmp)())
{
	t_list *p = *begin_list;
	void *temp = NULL;
	while ((*begin_list)->next)
	{
		if (cmp((*begin_list)->data, (*begin_list)->next->data) > 0)
		{
			temp = (*begin_list)->data;
			(*begin_list)->data = (*begin_list)->next->data;
			(*begin_list)->next->data = temp;
			*begin_list = p;
		}
		else
			*begin_list = (*begin_list)->next;
	}
	*begin_list = p;
}

int list_size(t_list *begin_list)
{
	int len = 0;
	while (begin_list)
	{
		len++;
		begin_list = begin_list->next;
	}
	return (len);
}

void list_reverse_fun(t_list **begin_list)
{
	t_list *first;
	t_list *middle;
	t_list *last;

	first = middle = NULL;
	last = *begin_list;
	while (last)
	{
		first = middle;
		middle = last;
		last = last->next;
		middle->next = first;
	}
	*begin_list = middle;
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
	printf("\n(1)\t"); display(start); printf("\n");
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	list_push_front(&start, (void *)"start");
	first = start;
	printf("(2)\t"); display(start); printf("\n");
	start = list_at(start, 3);
	printf("(3)\t"); display(start); printf("\n");
	printf("(4)\t"); display(first); printf("\n");
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	list_reverse(&start);
	printf("(5)\t"); display(start); printf("\n");

	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	list_reverse(&start);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	list_foreach(start, &display_data);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	list_foreach_if(first, &display_data, (void *)"start", &strcmp);
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	test = list_find(first, (void *)"and", &strcmp);
	printf("(7)\t"); display(test); printf("\n");
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	start = first;
	printf("(8)\t"); display(start); printf("\n");
	list_remove_if(&start, (void *)"and", &strcmp, &free_fct);
	printf("(9)\t"); display(start); printf("\n");
	printf("------------------------------------------------------------------------------------------\n\n");
	
	////////////////////////////////////////// <ex13> //////////////////////////////////////////////////////////
	char **buff1;
	buff1 = (char **)malloc(sizeof(char *) * 100);
	*(buff1 + 0) = create_string("cc");
	*(buff1 + 1) = create_string("oo");
	*(buff1 + 2) = create_string("zz");
    *(buff1 + 3) = create_string("bbe");
	*(buff1 + 4) = create_string("bb");
	*(buff1 + 5) = NULL;

	struct s_list *start1 = NULL;
	create(&start1, buff1, &find_size);
	printf("(a)\t"); display(start1); printf("\n");

	list_merge(&start, start1);
	printf("(b)\t"); display(start); printf("\n");

	///////////////////////////////////////// <ex14> //////////////////////////////////////////////////////////	
	list_sort(&start, &strcmp);
	printf("(c)\t"); display(start); printf("\n");
	first = start;
	///////////////////////////////////////// <ex15> //////////////////////////////////////////////////////////	
	list_reverse_fun(&start);
	printf("(d)\t"); display(start); printf("\n");
	
	///////////////////////////////////////// <ex16> //////////////////////////////////////////////////////////	
	list_reverse_fun(&start);
	//display(start);
	sorted_list_insert(&start, (void *)"a", &strcmp);
	display(start);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////// free memory ///////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	list_clear(start, &free_fct); //////////////////////////////////////////////////////////////////////////
	free(buff); ///////////////////////////////////////////////////////////////////////////////////////////////
	free(buff1); //////////////////////////////////////////////////////////////////////////////////////////////
	//free_memory(buff, &find_size);////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	return (0);
}
