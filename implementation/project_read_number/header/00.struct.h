typedef struct          s_list
{
	struct s_list        *next;
	char                 *num;
	char 				 *text;
	int					 digit_len;
}                        t_list;