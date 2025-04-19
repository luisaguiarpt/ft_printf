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
