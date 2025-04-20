#include "../libft/libft/libft.h"
#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;
	int		i;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			i++;
			count++;
		}
		else
		{
			i++;
			if (str[i] == 'c')
			{
				ft_putchar_fd((char)va_arg(args, int), 1);
				i++;
				count++;
			}
			else if (str[i] == 'd')
			{
				ft_putnbr_fd(va_arg(args, int), 1);
				i++;
				count++;
			}
		}
	}
	va_end(args);
	return (count);
}

void	*get_function(char c)
{
	t_functs	fnct_arr[];
	int			i;

	i = -1;
	fnct_arr[0].fs = 'c';
	fnct_arr[0].fnct = ft_putchar;
	fnct_arr[1].fs = 's';
	fnct_arr[1].fnct = ft_putstr;
	fnct_arr[2].fs = 'i';
	fnct_arr[2].fnct = ft_putnbr;
	fnct_arr[3].fs = 'd';
	fnct_arr[3].fnct = ft_putnbr;
	fnct_arr[4].fs = 'u';
	fnct_arr[4].fnct = ft_putnbr_u;
	fnct_arr[5].fs = 'x';
	fnct_arr[5].fnct = ft_putnbr_hex;
	fnct_arr[6].fs = 'X';
	fnct_arr[6].fnct = ft_putnbr_hex;
	fnct_arr[7].fs = 'p';
	fnct_arr[7].fnct = ft_putnbr_hex;
	fnct_arr[8].fs = '%';
	fnct_arr[8].fnct = ft_print_percent;
	while (++i < 9)
		if (c == fnct_arr[i].fs)
			return (fnct_arr[i].fnct);
	return (0);
}

#include <stdio.h>

int	main(void)
{
	char	c = 'a';
	int		d = 1;

	int		count = ft_printf("Print an a: %c\nPrint a 1: %d\n", c, d);
	printf("\n");
	int		count2 = printf("Print an a: %c\nPrint a 1: %d\n", c, d);
	
	printf("Count 1: %d\nCount 2: %d\n", count, count2);
}
