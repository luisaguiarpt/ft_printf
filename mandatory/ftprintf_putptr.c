/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:08:49 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/28 14:38:22 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_printf.h"

size_t	ft_putptr(unsigned long int n)
{
	unsigned char	c;
	const char		*hex;
	unsigned int	count;

	count = 0;
	hex = "0123456789abcdef";
	if (n == 0)
		return (ft_putstr("(nil)"));
	if (n > 15)
		count += ft_putptr(n / 16);
	c = hex[n % 16];
	if (count == 0)
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
	unsigned int	m = 0;

	int	a = 1;
	int	*ptr1 = &a;
	n = ft_putptr((unsigned long int)ptr1);
	printf("|%u\n", n);
	m = printf("%p", ptr1);
	printf("|%u\n-------------\n", m);

	char	*ptr2 = "ola";
	n = ft_putptr((unsigned long int)ptr2);
	printf("|%u\n", n);
	m = printf("%p", ptr2);
	printf("|%u\n-------------\n", m);
	
	n = ft_putptr(0);
	printf("|%u\n", n);
	m = printf("%p", (void *)0);
	printf("|%u\n-------------\n", m);
	m = 0;

	n = ft_putptr(5);
	printf("|%u\n", n);
	m = printf("%p", (void *)5);
	printf("|%u\n-------------\n", m);
	m = 0;

	n = ft_putptr(42);
	printf("|%u\n", n);
	m = printf("%p", (void *)42);
	printf("|%u\n-------------\n", m);
	m = 0;

	n = ft_putptr(101230);
	printf("|%u\n", n);
	m = printf("%p", (void *)101230);
	printf("|%u\n-------------\n", m);
	m = 0;

	n = ft_putptr(-123094);
	printf("|%u\n", n);
	m = printf("%p", (void *)-123094);
	printf("|%u\n-------------\n", m);
	m = 0;

	n = ft_putptr(-2147483647);
	printf("|%u\n", n);
	m = printf("%p", (void *)-2147483647);
	printf("|%u\n-------------\n", m);
	m = 0;

	n = ft_putptr(2147483647);
	printf("|%u\n", n);
	m = printf("%p", (void *)2147483647);
	printf("|%u\n-------------\n", m);
	m = 0;
}
*/
