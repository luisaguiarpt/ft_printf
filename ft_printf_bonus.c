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
#include "includes/ft_printf_bonus.h"
#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	size_t		count;
	va_list		args;
	int			i;
	t_format	*format;

	format = NULL;
	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			count += write(1, &str[i++], 1);
		else if (str[i++] == '%')
		{
			if (!init_flags(&format))
				return (-1);
			i += parse_str(&str[i], format);
			if (format->error > 0)
				return (-1);
			count += get_function(format, format->type, args);
		}
	}
	va_end(args);
	free(format);
	return (count);
}

int	parse_str(const char *str, t_format *format)
{
	int	i;

	i = 0;
	while (is_flag(str[i]) && str[i])
		get_flags(str[i++], format);
	if (ft_isdigit(str[i]) && str[i])
		i += get_nbr(&str[i], format, 'n');
	if (is_max(&str[i]) && str[i])
	{
		++i;
		i += get_nbr(&str[i], format, 'x');
	}
	if (is_type(str[i]) && str[i])
		i += get_type(str[i], format);
	check_error(format);
	return (i);
}

void	get_flags(char c, t_format *format)
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

void	check_error(t_format *format)
{
	if (format->zero > 1 || format->hash > 1 || format->plus > 1)
		format->error = 1;
	if (format->minus > 1 || format->blank > 1)
		format->error = 1;
}

int	init_flags(t_format **f_ptr)
{
	t_format	*format;

	format = malloc(sizeof(t_format));
	if (!format)
		return (0);
	if (*f_ptr != NULL)
		free(*f_ptr);
	*f_ptr = format;
	format->zero = 0;
	format->hash = 0;
	format->plus = 0;
	format->minus = 0;
	format->blank = 0;
	format->min = 0;
	format->max = 0;
	format->type = '\0';
	format->error = 0;
	return (1);
}

size_t	get_function(t_format *format, char c, va_list args)
{
	if (c == 'c')
		return (putchar_format(va_arg(args, int), format));
	else if (c == 's')
		return (putstr_format(va_arg(args, char *), format));
	else if (c == 'i' || c == 'd')
		return (putnbr_format(va_arg(args, int), format));
	else if (c == 'u')
		return (putnbr_u_format(va_arg(args, unsigned int), format));
	else if (c == 'x')
		return (puthex_format(va_arg(args, int), 0, format));
	else if (c == 'X')
		return (puthex_format(va_arg(args, int), 1, format));
	else if (c == 'p')
		return (putptr_pad(va_arg(args, unsigned long), format));
	else if (c == '%')
		return (putchar_format('%', format));
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
