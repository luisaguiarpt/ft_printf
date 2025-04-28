/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:30:02 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/28 15:04:50 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

size_t	get_function(char c, va_list args, t_format format);
int	is_flag(char c);
int	check_flags(char c, t_format *format);
void	init_flags(t_flags *format);

int	ft_printf(const char *str, ...)
{
	size_t		count;
	va_list		args;
	int			i;
	t_format	format;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			count += write(1, &str[i], 1);
		else if (str[i++] == '%')
		{
			init_flags(format);
			i += parse_str(&str[i], format);
			if (format->error > 0)
				return (-1);
			count += get_function(format->type, args, format);
		}
	}
	va_end(args);
	return (count);
}

int	parse_str(char	*str, t_format *format)
{
	int	i;

	i = 0;
	while (is_flag(str[i]) && str[i])
		get_flags(str[i++], t_format format);
	if (is_digit(&str[i]) && str[i])
		i += get_nbr(str[i]);
	if (is_max(str[i]) && str[i])
		i += get_nbr(str[i]);
	if (is_type(str[i]) && str[i])
		get_type(str[i]);
	check_error(format);
	return (i);
}

int	get_flags(char c, t_format *format)
{
	if (c == '0')
		format->zero += 1;
	if (c == '#')
		format->hash += 1;
	if (c == '+')
		format->plus += 1;
	if (c == '-')
		format->minus += 1;
	if (c == ' ')
		format->blank += 1;
}

void	check_error(t_format format)
{
	if (format->zero > 1 || format->hash > 1 || format->plus > 1)
		format->error = 1;
	if (format->minus > 1 || format->blank > 1)
		format->error = 1;
}

void	init_flags(t_flags *format)
{
	format->zero = 0;
	format->hash = 0;
	format->plus = 0;
	format->minus = 0;
	format->blank = 0;
	format->min = 0;
	format->max = 0;
	format->type = '\0';
	format->error = 0;
}

size_t	get_function(t_format format, char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int), t_format format));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *), t_format format));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(args, int), t_format format));
	else if (c == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int), t_format format));
	else if (c == 'x')
		return (ft_puthex(va_arg(args, int), 0, t_format format));
	else if (c == 'X')
		return (ft_puthex(va_arg(args, int), 1, t_format format));
	else if (c == 'p')
		return (ft_puthex_u(va_arg(args, unsigned long), t_format format));
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
