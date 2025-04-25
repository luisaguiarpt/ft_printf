/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:08:49 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/25 22:09:16 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_u(unsigned int n)
{
	char	c;
	size_t	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
	}
	c = (n % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}
