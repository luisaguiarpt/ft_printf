/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:30:02 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/28 15:04:50 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"
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
			count += get_function(format, format->type, args);
		}
	}
	va_end(args);
	free(format);
	return (count);
}
