/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:08:49 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/27 20:05:08 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

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
/*
#include <stdio.h>

int	main(void)
{
	int	n = 0;

	n = ft_putnbr(0);
	printf("|%i\n", n);
	printf("|%i\n", 0);
	n = ft_putnbr(9);
	printf("|%i\n", n);
	printf("|%i\n", 9);
	n = ft_putnbr(9876);
	printf("|%i\n", n);
	printf("|%i\n", 9876);
	n = ft_putnbr(-1243);
	printf("|%i\n", n);
	printf("|%i\n", -1243);
	n = ft_putnbr(-2147483648);
	printf("|%i\n", n);
	printf("|%i\n", INT_MIN);
	n = ft_putnbr(2147483647);
	printf("|%i\n", n);
	printf("|%i\n", 2147483647);
}
*/
