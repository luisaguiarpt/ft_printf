/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:08:49 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/28 15:02:07 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

size_t	puthex_format(unsigned int n, int up, t_format *format)
{
	unsigned char	c;
	const char		*hex;
	size_t			count;

	count = 0;
	if (up)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n > 15)
		count += puthex_format(n / 16, up, format);
	c = hex[n % 16];
	if (count == 0 && format->hash == 1)
	{
		write(1, "0x", 2);
		count += 2;
	}
	write(1, &c, 1);
	count++;
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	unsigned int	n = 0;
	n = ft_puthex(0);
	printf("|%u\n", n);
	printf("|%x\n", 0);
	n = ft_puthex(5);
	printf("|%u\n", n);
	printf("|%x\n", 5);
	n = ft_puthex(42);
	printf("|%u\n", n);
	printf("|%x\n", 42);
	n = ft_puthex(101230);
	printf("|%u\n", n);
	printf("|%x\n", 101230);
	n = ft_puthex(-123094);
	printf("|%u\n", n);
	printf("|%x\n", -123094);
	n = ft_puthex(-2147483647);
	printf("|%u\n", n);
	printf("|%x\n", -2147483647);
	n = ft_puthex(2147483647);
	printf("|%u\n", n);
	printf("|%x\n", 2147483647);
}
*/
