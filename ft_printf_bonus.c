/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:30:02 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/26 20:46:56 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

size_t	get_function(char c, va_list args);

int	ft_printf(const char *str, ...)
{
	size_t	count;
	va_list	args;
	int		i;
	t_flags	flags;

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
		else if (str[i++] == '%')
		{
			parse_str(&str[i]);
			count += get_function(str[i++], args);
		}
	}
	va_end(args);
	return (count);
}

void	parse_str(char	*str, t_flags *flags)
{
	int	i;
	int	end;

	i = 0;
	end = 0;
	while (!end)
	{
		if (str[i
	}
}

void	init_flags(t_flags *flags)
{
	flags->zero = 0;
	flags->hash= 0;
	flags->minus= 0;
	flags->plus= 0;
	flags->blank= 0;
	flags->precision= 0;
	flags->min= 0;
	flags->type= i;
}

size_t	get_function(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_puthex(va_arg(args, int), 0));
	else if (c == 'X')
		return (ft_puthex(va_arg(args, int), 1));
	else if (c == 'p')
		return (ft_puthex_u(va_arg(args, unsigned long)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}
/*
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
*/
