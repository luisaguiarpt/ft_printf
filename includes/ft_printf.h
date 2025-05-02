/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:28:43 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/27 19:32:51 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int		ft_printf(const char *str, ...);
size_t	ft_putchar(char c);
size_t	ft_putstr(char *s);
size_t	ft_putnbr_u(unsigned int n);
size_t	ft_putnbr(int n);
size_t	ft_puthex(unsigned int n, int up);
size_t	ft_putptr(unsigned long int n);

#endif
