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

static size_t	puthex(unsigned int n, t_format *format);
static size_t	put_zeros(unsigned int n, t_format *format, int put);
static size_t	put_spaces(unsigned int n, t_format *format);
static size_t	put_hash(t_format *format);

size_t	puthex_format(unsigned int n, t_format *format)
{
	size_t	count;

	count = 0;
	if (!format->minus)
		count += put_spaces(n, format);
	if (!format->hash)
		count += put_hash(format);
	count += put_zeros(n, format, 1);
	count += puthex(n, format);
	if (format->minus)
		count += put_spaces(n, format);
	return (count);
}

static size_t	puthex(unsigned int n, t_format *format)
{
	unsigned char	c;
	const char		*hex;
	size_t			count;

	count = 0;
	if (format->prec && !format->max && n == 0)
		return (0);
	if (format->type == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n > 15)
		count += puthex(n / 16, format);
	c = hex[n % 16];
	write(1, &c, 1);
	count++;
	return (count);
}

static size_t	put_hash(t_format *format)
{
	if (format->hash && format->type == 'x')
	{
		write(1, "0x", 2);
		return (2);
	}
	else if (format->hash && format->type == 'X')
	{
		write(1, "0X", 2);
		return (2);
	}
	return (0);
}

static size_t	put_spaces(unsigned int n, t_format *format)
{
	size_t	spaces;
	size_t	zeros;
	size_t	i;

	spaces = 0;
	zeros = put_zeros(n, format, 0);
	i = 0;
	if (hex_nbr_dig(n) > format->min)
		return (spaces);
	if (hex_nbr_dig(n) < format->min && format->min > format->max)
	{
		spaces = format->min - hex_nbr_dig(n);
		if (format->plus || format->blank)
			spaces -= 1;
	}
	spaces = spaces - (zeros * (spaces >= zeros));
	if (format->prec && !format->max && n == 0)
		spaces += 1;
	while (i < spaces)
	{
		write(1, " ", 1);
		i++;
	}
	return (spaces);
}

static size_t	put_zeros(unsigned int n, t_format *format, int put)
{
	size_t	zeros;
	size_t	i;

	i = 0;
	if (format->zero && format->min && !format->prec)
		zeros = pos_diff_ui(format->min, hex_nbr_dig(n));
	else if (!format->min && format->prec)
		zeros = pos_diff_ui(format->max, hex_nbr_dig(n));
	else if (format->min && format->prec)
		zeros = pos_diff_ui(format->max, hex_nbr_dig(n));
	else
		zeros = 0;
	while (i < zeros && put)
	{
		write(1, "0", 1);
		i++;
	}
	return (zeros);
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
