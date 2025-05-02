/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:09:09 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/29 16:29:54 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"
#include "../libft/libft.h"

static size_t	putnstr(char *str, size_t n);
static size_t	put_spaces(char *str, t_format *format);

size_t	putstr_format(char *s, t_format *format)
{
	size_t	i;

	i = 0;
	if (!s)
		putstr_format("(null)", format);
	if (!format->minus)
		i += put_spaces(s, format);
	i += putnstr(s, format->max);
	if (format->minus)
		i += put_spaces(s, format);
	return (i);
}

static size_t	putnstr(char *str, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		n = ft_strlen(str);
	while (i < n && str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static size_t	put_spaces(char *str, t_format *format)
{
	size_t	spaces;

	spaces = 0;
	if (!format->max && format->min >= ft_strlen(str))
		spaces = format->min - ft_strlen(str);
	else if (!format->max && ft_strlen(str) > format->min)
		spaces = 0;
	else if (format->max >= ft_strlen(str) && format->min >= ft_strlen(str))
		spaces = format->min - ft_strlen(str);
	else if (format->max < ft_strlen(str) && format->min >= ft_strlen(str))
		spaces = format->min - ft_strlen(str) - format->max;
	return (spaces);
}
/*
int	main(void)
{
	t_format	*format;
	
	format = malloc(sizeof(t_format));
	format->minus = 1;
	format->min = 4;
	format->max = 4;

	char	*str = "Hello";
	ft_putstr(str, format);
}
*/
