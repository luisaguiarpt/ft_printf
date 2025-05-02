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
