#include <unistd.h>
#include <stdio.h>

void	address_to_hex(unsigned long long int addr)
{
	int		i;
	char	arr[16];

	i = 0;
	while (i < 16)
	{
		arr[15 - i] = "0123456789abcdef"[addr % 16];
		addr = addr / 16;
		i++;
	}

	write(1, arr, 16);
	write(1, ":", 1);
}

void	char_to_hex(unsigned char content, char content_hex[])
{
	if (content / 16 < 10)
		content_hex[0] = content / 16 + '0';
	else
		content_hex[0] = content / 16 + 87;
	if (content % 16 < 10)
		content_hex[1] = content % 16 + '0';
	else
		content_hex[1] = content % 16 + 87;
}

void	content_to_hex(unsigned char *content, int frequency)
{
	int	i;
	char content_hex[2];

	i = 0;
    while (i < frequency)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		char_to_hex(content[i], content_hex);
		write(1, content_hex, 2);
		i++;
	}
}

void	print_printable(unsigned char *content, int frequency)
{
	int	i;

	i = 0;
	while (i < frequency)
	{
		if (content[i] < 32 || content[i] > 126)
			write(1, ".", 1);
		else
			write(1, &content[i], 1);
		i++;
	}
}

void	*print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				frequency;

	i = 0;
	if (size > 0)
	{
		while (i * 16 <= size)
		{
			if ((i + 1) * 16 <= size)
				frequency = 16;
			else
				frequency = size % 16;
        	address_to_hex((unsigned long long int)addr + (i * 16));
        	content_to_hex((unsigned char *)addr + (i * 16), frequency);
        	write(1, " ", 1);
        	print_printable((unsigned char *)addr + (i * 16), frequency);
        	write(1, "\n", 1);
        	i++;
		}
	}
	return (addr);
}

int 	main()
{
	char	empty[] = "";
	print_memory((void *)empty, sizeof(empty));
	char	str[] = "Bonjour les amin----";
	print_memory((void *)str, sizeof(str));
	char	str1[] = "ches\t\n\tc  es--t fo----";
	print_memory((void *)str1, sizeof(str1));
	char	str2[] = "u\ttout\tce qu on ----";
	print_memory((void *)str2, sizeof(str2));
	char	str3[] = "peut faire avec\t----";
	print_memory((void *)str3, sizeof(str3));
	char	str4[] = "\n\tprint_memory\n\n----";
	print_memory((void *)str4, sizeof(str4));
	char 	str5[] = "\n\tlol.lol\n \0";
	print_memory((void *)str5, sizeof(str5));
	char 	str6[] = "hello world h...ello wo\t\trld";
	print_memory((void *)str6, 0);
    char    str7[] = "Bonjour les aminches\n\n\n c est fou\ttout.ce quonpeut faire avec\b\b\bprint_memory\t\t\t\tlol\tlol\t \tl";
    print_memory((void *)str7, sizeof(str7));
	char    str8[] = "hello";
    print_memory((void *)str8, sizeof(str8));
	
}
