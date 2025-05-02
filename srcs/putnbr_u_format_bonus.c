/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:08:49 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/29 21:13:00 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"
#include "../libft/libft.h"

static size_t	put_spaces(unsigned int n, t_format *format);
static size_t	put_zeros(unsigned int n, t_format *format, int put);
static size_t	put_nbr_u(unsigned int n);

size_t	putnbr_u_format(unsigned int n, t_format *format)
{
	size_t	count;

	count = 0;
	if (!format->minus)
		count += put_spaces(n, format);
	count += put_zeros(n, format, 1);
	count += put_nbr_u(n);
	if (format->minus)
		count += put_spaces(n, format);
	return (count);
}

static size_t	put_zeros(unsigned int n, t_format *format, int put)
{
	size_t	zeros;
	size_t	i;

	i = 0;
	if (abs_nbr_dig(n) > format->max)
		zeros = 0;
	else
		zeros = format->max - u_nbr_dig(n);
	while (i < zeros && put)
	{
		write(1, "0", 1);
		i++;
	}
	return (zeros);
}

static size_t	put_spaces(unsigned int n, t_format *format)
{
	size_t	spaces;
	size_t	zeros;
	size_t	i;

	spaces = 0;
	zeros = put_zeros(n, format, 0);
	i = 0;
	if (abs_nbr_dig(n) > format->min)
		return (spaces);
	if (abs_nbr_dig(n) < format->min)
		spaces = format->min - u_nbr_dig(n);
	if (spaces >= zeros)
		spaces -= zeros;
	else
		spaces = 0;
	while (i < spaces)
	{
		write(1, " ", 1);
		i++;
	}
	return (spaces);
}

static size_t	put_nbr_u(unsigned int n)
{
	char	c;
	size_t	count;

	count = 0;
	if (n > 9)
		count += put_nbr_u(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	int	n = 0;
	int	m = 0;

	t_format	*format;

	format = malloc(sizeof(t_format));
	format->min = 9;
	format->max = 6;
	format->minus = 0;
	format->zero = 1;
	format->plus = 1;

	n = putnbr_format(1243, format);
	printf("|%i\n", n);
	m = printf("%+09i", 1243);
	printf("|%i\n", m);
	printf("------------------\n");
	n = putnbr_format(1234, format);
	printf("|%i\n", n);
	m = printf("%+09i", 1234);
	printf("|%i\n", m);
	printf("------------------\n");
	n = putnbr_format(9876, format);
	printf("|%i\n", n);
	m = printf("%+09i", 9876);
	printf("|%i\n", m);
	printf("------------------\n");
	n = putnbr_format(-1243, format);
	printf("|%i\n", n);
	m = printf("%+09i", -1243);
	printf("|%i\n", m);
	printf("------------------\n");
	n = putnbr_format(-21648, format);
	printf("|%i\n", n);
	m = printf("%+09i", -21648);
	printf("|%i\n", m);
	printf("------------------\n");
	n = putnbr_format(2147, format);
	printf("|%i\n", n);
	m = printf("%+09i", 2147);
	printf("|%i\n", m);
}
*/
