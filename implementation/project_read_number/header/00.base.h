#ifndef BASE_H
# define BASE_H

#include "./00.struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

t_list  *create_linked_list(char *dict_num[], char *dict_char[]);

void    create_dictionary(char ***dict_num, char ***dict_char, char **data_ref, int buffer_size);
void    display_lst(t_list *head);
void    display_string(char *str);
void    free_lst(t_list *head);
int     find_size();
char	*ft_itoa(int nb);
int     ft_atoi(char *str);
char    **ft_split(char *str, char *charset);
int     ft_strlen(char *str);
int     ft_nbrcmp(int nb1, int nb2);
int     ft_strcmp(char *s1, char *s2);
void    find_res(t_list *head, char *str);
int     is_error(char *str);
int     is_charset(char c, char *charset);
int	    len(long nb);
int     len_count(char *str, char *charset);
void    memory_manager(char *buffer, char **result, char **dict_num, char **dict_char);
void    memory_manager2(char *str);
void    preprocess_dictionary(char ***dict_num, char ***dict_char);
void    read_dictionary(char *str);
void    search_text(t_list *head, int idx);
int     search_len_idx(t_list *head, int idx);
void    search_nbr_lst(t_list *head, char *str);
void    string_duplicate(char **buffer, int size);
void    word_copy(char *dest, char *src, char *charset);
int     word_count(char *str, char *charset);

#endif