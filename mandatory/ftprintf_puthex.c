/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:08:49 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/29 14:21:18 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_puthex(unsigned int n, int up)
{
	unsigned char	c;
	const char		*hex;
	unsigned int	count;

	count = 0;
	if (up)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n > 15)
		count += ft_puthex(n / 16, up);
	c = hex[n % 16];
	write(1, &c, 1);
	count++;
	return (count);
}
//
//#include <stdio.h>
//
//int	main(void)
//{
//	unsigned int	n = 0;
//	n = ft_puthex(0, 0);
//	printf("|%u\n", n);
//	printf("%x\n", 0);
//	printf("--------------------\n");
//	n = ft_puthex(5, 0);
//	printf("|%u\n", n);
//	printf("%x\n", 5);
//	printf("--------------------\n");
//	n = ft_puthex(42, 0);
//	printf("|%u\n", n);
//	printf("%x\n", 42);
//	printf("--------------------\n");
//	n = ft_puthex(101230, 0);
//	printf("|%u\n", n);
//	printf("%x\n", 101230);
//	printf("--------------------\n");
//	n = ft_puthex(-123094, 0);
//	printf("|%u\n", n);
//	printf("%x\n", -123094);
//	printf("--------------------\n");
//	n = ft_puthex(-2147483647, 0);
//	printf("|%u\n", n);
//	printf("%x\n", -2147483647);
//	printf("--------------------\n");
//	n = ft_puthex(2147483647, 0);
//	printf("|%u\n", n);
//	printf("%x\n", 2147483647);
//	printf("--------------------\n");
//}
//
