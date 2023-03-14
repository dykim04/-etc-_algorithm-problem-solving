#include "../header/00.base.h"

int ft_numlen(char *str)
{
    int len = 0;
    while (*str)
    {
        if (!(*str >= '0' && *str <= '9'))
            return (len);
        len++;
        str++;
    }
    return (len);
}

char *preprocess_str(char *str, char *string, int _len, int len)
{
    int i = -1;
    int k = 0;
    char buff[1000];
    string[len] = 0;
    while (++i < 1000)
        buff[i] = 0;
    i = -1;
    while (++i < _len)
        buff[i] = str[i];
    i= -1;
    while (++i < _len)
        string[i] = 0;
    i = -1;
    while (++i < len - _len)
        string[i] = '0';
    while (i < len)
    {
        string[i] = buff[k];
        k++;
        i++;
    }
    return (string);
}

void hundred_set(t_list *head, char *str, int flag, int minus)
{
    int hundred = (str[0] - '0'); 
    int ten = (str[1] - '0') * 10 + (str[2] -'0') * 1;
    int one;
    char *itoa_hundred;
    char *itoa_100;
    char *itoa_ten;
    char *itoa_one;
    if (hundred)
    {
        itoa_hundred = ft_itoa(hundred);
        search_nbr_lst(head, itoa_hundred);
        if (ft_atoi(str + 1) || !(str + 3)[0])
            printf(" ");
        itoa_100 = ft_itoa(100);
        search_nbr_lst(head, itoa_100);
        free(itoa_hundred);
        free(itoa_100);
        if ((str + 3)[0] || str[2] != '0')
            printf(" ");
    }
    if (ten >= 10 && ten < 20)
    {
        itoa_ten = ft_itoa(ten);
        search_nbr_lst(head, itoa_ten);
        free(itoa_ten);
        if (flag != 1)
            printf(" ");
    }
    else
    {
        ten = (str[1] - '0') * 10;
        if (ten)
        {
            itoa_ten = ft_itoa(ten);
            search_nbr_lst(head, itoa_ten);
            free(itoa_ten);
        }
        one = (str[2] - '0');
        if (one)
        {    
            if (str[1] != '0')    
                printf(" ");
            itoa_one = ft_itoa(one);
            search_nbr_lst(head, itoa_one);
            free(itoa_one);
            if (flag != 1)
                printf(" ");
        }
    }
    if (flag != 1) 
    {
        if (!one && !ten && !hundred)
            return ;
        if (flag == 2)
        {
            search_text(head, 4);
            if (ft_atoi(str + 3))
                printf(" ");
        }
        else
        {
            search_text(head, ((2 * flag) + minus));
            printf(" ");
        }
    }
}

void find_res(t_list *head, char *str)
{
    // display_lst(head);
    int len = ft_numlen(str);
    int _len = len;
    int rotation = 0;
    int minus = 0;
    char *string;
    char *ptr;
    int flag = 0;
    while (len % 3 != 0)
        len++;
    string = (char *)malloc(sizeof(char) * (len + 1));
    rotation = len / 3;
    if (rotation != 1)
        minus = rotation - 2;
    string = preprocess_str(str, string, _len, len);
    // printf("%s\n", string);
    ptr = string;
    while (rotation > 0 )
    {
        if (minus == 0)
            minus = 0;
        if (!ft_atoi(string) && !flag)
        {
            search_nbr_lst(head, ft_itoa(0));
            printf("\n");
            return ;
        }
        flag = 1;
        hundred_set(head, string, rotation, minus);
        string = string + 3;
        rotation--;
        minus--;
    }
    memory_manager2(ptr);
    printf("\n");
}