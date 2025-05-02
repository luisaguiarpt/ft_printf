/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:08:49 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/29 18:30:44 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

size_t	ft_putnbr_u(unsigned int n, t_format *format)
{
	char	c;
	size_t	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putnbr_u(n / 10, format);
	}
	c = (n % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}
