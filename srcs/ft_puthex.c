/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:08:49 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/15 10:43:02 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_puthex(unsigned int n)
{
	unsigned char	c;
	const char		*hex;

	hex = "0123456789abcdef";
	if (n > 15)
		ft_puthex(n / 16);
	c = hex[n % 16];
	write(1, &c, 1);
}

#include <stdio.h>

int	main(void)
{
	ft_puthex(0);
	printf("|%x\n", 0);
	ft_puthex(5);
	printf("|%x\n", 5);
	ft_puthex(42);
	printf("|%x\n", 42);
	ft_puthex(101230);
	printf("|%x\n", 101230);
	ft_puthex(-123094);
	printf("|%x\n", -123094);
	ft_puthex(-2147483647);
	printf("|%x\n", -2147483647);
	ft_puthex(2147483647);
	printf("|%x\n", 2147483647);
}
