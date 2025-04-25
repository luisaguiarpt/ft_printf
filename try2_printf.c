/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try2_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:30:02 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/25 22:10:42 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

void	*get_function(char c);

int	ft_printf(const char *str, ...)
{
	size_t	count;
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
			count += get_function(str[i]);
	}
	va_end(args);
	return (count);
}

void	*get_function(char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, char)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_puthex(va_arg(args, int)));
	else if (c == 'X')
		return (ft_puthex_u(va_arg(args, int)));
	else if (c == 'p')
		return (ft_puthex(va_arg(args, int)));
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
