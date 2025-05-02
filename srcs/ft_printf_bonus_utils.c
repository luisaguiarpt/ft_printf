/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:07:19 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/28 13:18:09 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf_bonus.h"

int	is_flag(char c)
{
	if (c == '0' || c == '#' || c == '+' || c == '-' || c == ' ')
		return (1);
	return (0);
}

int	is_max(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '.')
		i++;
	else
		return (0);
	if (ft_isdigit(str[i]))
		return (1);
	return (0);
}

int	is_type(char c)
{
	if (c == 'i' || c == 'd' || c == 'u' || c == 'p')
		return (1);
	if (c == 'x' || c == 'X' || c == 'c' || c == 's')
		return (1);
	return (0);
}

int	get_type(char c, t_format *format)
{
	if (c == 'i')
		format->type = 'i';
	if (c == 'd')
		format->type = 'd';
	if (c == 'u')
		format->type = 'u';
	if (c == 'x')
		format->type = 'x';
	if (c == 'X')
		format->type = 'X';
	if (c == 'p')
		format->type = 'p';
	if (c == 'c')
		format->type = 'c';
	if (c == 's')
		format->type = 's';
	if (c == '%')
		format->type = '%';
	if (c == 'i' || c == 'd' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	else if (c == 'p' || c == 'c' || c == 's' || c == '%')
		return (1);
	return (0);
}

int	get_nbr(const char *str, t_format *format, char min_max)
{
	int	nbr;
	int	i;

	nbr = 0;
	i = 0;
	while (ft_isdigit(str[i]))
	{
		nbr = (nbr * 10) + str[i] - '0';
		i++;
	}
	if (min_max == 'n')
		format->min = nbr;
	if (min_max == 'x')
		format->max = nbr;
	return (i);
}
