#include "../header/00.base.h"

int ft_strcmp(char *s1, char *s2)
{
    int idx = 0;
    while (s1[idx] && (s1[idx] == s2[idx]))
        idx++;
    return (s1[idx] - s2[idx]);
}

void ft_putstr(char *str)
{
    printf("%s", str);
}

void display_lst(t_list *head)
{
    while (head)
    {
        printf("%s ", head->num);
        printf("%s ", head->text);
        printf("%d\n", head->digit_len);

        head = head->next;
    }
}

int is_valid(char *num)
{
    int len = ft_strlen(num);
    int i = 1;
    if (num[0] != '1')
        return (0);
    while (i < len)
    {
        if (num[i] != '0')
            return (0);
        i++;
    }
    return (1);
}

void search_nbr_lst(t_list *head, char *str)
{
    while (head)
    {
        if (ft_strcmp(head->num, str) == 0)
        {
            printf("%s", head->text);
            return ;
        }
        head = head->next;
    }
}

void search_text(t_list *head, int idx)
{
    while (head)
    {
        if (ft_nbrcmp(head->digit_len, idx) == 0)
        {
            printf("%s", head->text);
            return ;
        }
        head = head->next;
    }
}

t_list *create_linked_list(char *dict_num[], char *dict_char[])
{
    t_list *head;
    t_list *ptr;
    t_list *new;
    int idx = 1;
    int lst_size = 0;
    while (dict_num[lst_size])
        lst_size++;
    head = (t_list *)malloc(sizeof(t_list) * 1);
    head->next = NULL;
    head->num = dict_num[0];
    head->text = dict_char[0];
    head->digit_len = 0;
    ptr = head;
    while (idx < lst_size)
    {
        new = (t_list *)malloc(sizeof(t_list) * 1);
        new->next = NULL;
        new->num = dict_num[idx];
        new->text = dict_char[idx];
        if (ft_strlen(new->num) >= 3 && is_valid(new->num))
            new->digit_len = ft_strlen(new->num);
        else
            new->digit_len = 0;
        ptr->next = new;
        ptr = new;
        idx++;
    }
    return (head);
}