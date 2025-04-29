/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:08:49 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/29 21:13:00 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"
#include "../libft/libft.h"

size_t	putnbr_format(int n, t_format *format)
{
	size_t	min;
	size_t	max;
	size_t	zeroes;
	size_t	i;
	size_t	j;

	i = 0;
	min = format->min;
	max = format->max;
	zeroes = min - max - (n < 0);
	if (!format->minus && (min > nbr_dig(n) || min > max))
		while (i++ < min - (min > nbr_dig(n) * nbr_dig(n) + (min > max) * max))
			write(1, " ", 1);
	if (n < 0)
	{
		write(1, "-", 1);
		i++;
	}
	while (zeroes--)
		write(1, "0", 1);
	ft_putnbr(n * ((n < 0) * -1 + 1 * (n > 0)));
	j = 0;
	if (!format->minus && (min > nbr_dig(n) || min > max))
		while (i++ < min - (min > nbr_dig(n) * nbr_dig(n) + (min > max) * max))
			write(1, " ", 1);
	return (i);
}

size_t	ft_putnbr(int n)
{
	char	c;
	size_t	count;

	count = 0;
	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		count++;
		write(1, "-", 1);
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

#include <stdio.h>

int	main(void)
{
	int	n = 0;
	int	m = 0;

	t_format	*format;

	format = malloc(sizeof(t_format));
	format->min = 9;
	format->max = 6;
	format->minus = 1;

	n = putnbr_format(1243, format);
	printf("|%i\n", n);
	m = printf("%-9.6i", 1243);
	printf("|%i\n", m);
	printf("------------------\n");
	n = putnbr_format(1234, format);
	printf("|%i\n", n);
	m = printf("%-9.6i", 1234);
	printf("|%i\n", m);
	printf("------------------\n");
	n = putnbr_format(9876, format);
	printf("|%i\n", n);
	m = printf("%-9.6i", 9876);
	printf("|%i\n", m);
	printf("------------------\n");
	n = putnbr_format(-1243, format);
	printf("|%i\n", n);
	m = printf("%-9.6i", -1243);
	printf("|%i\n", m);
	printf("------------------\n");
	n = putnbr_format(-21648, format);
	printf("|%i\n", n);
	m = printf("%-9.6i", -21648);
	printf("|%i\n", m);
	printf("------------------\n");
	n = putnbr_format(2147, format);
	printf("|%i\n", n);
	m = printf("%-9.6i", 2147);
	printf("|%i\n", m);
}

