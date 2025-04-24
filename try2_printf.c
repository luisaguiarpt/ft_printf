#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

void	*get_function(char c);

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
			count++;
			write(1, &str[i++], 1);
		}
		else
		{
			if (str[i] == 'c')
				get_function(str[i])(va_arg(args, int));
			else if (str[i] == 'd')
				get_function(str[i])(va_arg(args, int));
		}
	}
	va_end(args);
	return (count);
}

void	*get_function(char c)
{
	if (c == 'c')
		return (ft_putchar);
	else if (c == 's')
		return (ft_putstr);
	else if (c == 'i' || c == 'd')
		return (ft_putnbr);
	else if (c == 'u')
		return (ft_putnbr_u);
	else if (c == 'x')
		return (ft_puthex);
	else if (c == 'X')
		return (ft_puthex_u);
	else if (c == 'p')
		return (ft_puthex);
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
