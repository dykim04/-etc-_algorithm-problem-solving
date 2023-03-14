#include "../header/00.base.h"

void free_lst(t_list *head)
{
    t_list *p = head;
    while (head)
    {
        p = head;
        head = head->next;
        free(p);
    }
}

void memory_manager2(char *str)
{
    free(str);
}

void memory_manager(char *buffer, char **result, char **dict_num, char **dict_char)
{
	int i ;

	free(buffer);
	i = -1;
	while (result[++i])
		free(result[i]);
	free(result);
	i = -1;
	while (dict_num[++i])
	{
		free(dict_num[i]);
		free(dict_char[i]);
	}
	free(dict_num);
	free(dict_char);
}