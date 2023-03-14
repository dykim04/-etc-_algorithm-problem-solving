#include "../header/00.base.h"

int is_charset(char c, char *charset)
{
    int idx;

    idx = 0;
    while (charset[idx])
    {
        if (c != charset[idx])
            return (0);
        idx++;
    }
    return (1);
}

int word_count(char *str, char *charset)
{
    int idx;
    int count_next;
    int word_count;

    word_count = 0;
    idx = 0;
    count_next = 1;
    while (str[idx])
    {
        if (!is_charset(str[idx], charset) && count_next)
        {
            count_next = 0;
            word_count++;
        }
        if (is_charset(str[idx], charset))
            count_next = 1;
        idx++;
    }
    return (word_count);
} 

int len_count(char *str, char *charset)
{
    int word_len;

    word_len = 0;
    while (!is_charset(*str, charset) && *str)
    {
        word_len++;
        str++;
    }
    return (word_len);
}

void word_copy(char *dest, char *src, char *charset)
{
    int src_idx;
    int dest_idx;

    src_idx = 0;
    dest_idx = 0;
    while (src[src_idx] && !is_charset(src[src_idx], charset))
    {
        dest[dest_idx] = src[src_idx];
        dest_idx++;
        src_idx++;
    }
    dest[dest_idx] = '\0';
}

char **ft_split(char *str, char *charset)
{
    unsigned int word_no;
    unsigned int words;
    unsigned int word_len;
    char **res;

    word_no = 0;
    words = word_count(str, charset);
    res = (char **)malloc(sizeof(char *) * (words + 1));
	if (words == 0)
	{
		*res = NULL;
		return (res);
	}
    res[words] = NULL;
    while (word_no < words)
    {
        while (is_charset(*str, charset))
            str++;
        word_len = len_count(str, charset);
        res[word_no] = (char *)malloc(sizeof(char) * ((word_len) +  1));
        res[word_no][word_len] = '\0';
        word_copy(res[word_no], str, charset);
        str = str + word_len;
        word_no++;
    }
    return (res);
}