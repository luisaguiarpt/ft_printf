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

size_t	ft_putstr_null(t_format *format);

size_t	ft_putstr(char *s, t_format *format)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s)
		return (ft_putstr_null(format));
	if (!format->minus && format->min > format->max)
		while (i < format->min - format->max)
		{
			write(1, " ", 1);
			i++;
		}
	j = 0;
	while (s[j] && (j < format->max || format->max == 0))
	{
		write(1, &s[j++], 1);
		i++;
	}
	if (format->minus && format->min > format->max)
		while (i++ - j < format->min - format->max)
			write(1, " ", 1);
	return (i);
}

size_t	ft_putstr_null(t_format *format)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (format->max)
		while (i++ < format->min)
			write(1, " ", 1);
	if (format->max)
		return (i);
	if (!format->minus)
		while (i++ < format->min - 6)
			write(1, " ", 1);
	ft_putstr_fd("(null)", 1);
	i += 6;
	j = 0;
	if (format->minus)
		while (j++ < format->min - 6 && i++)
			write(1, " ", 1);
	return (i);
}

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
