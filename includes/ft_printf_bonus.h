/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:28:43 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/29 20:59:54 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

typedef struct	s_format
{
	int		zero;
	int		hash;
	int		plus;
	int		minus;
	int		blank;
	size_t	min;
	size_t	max;
	char	type;
	int		error;
}				t_format;

int	ft_printf(const char *str, ...);
size_t	ft_putchar(char c, t_format *format);
size_t	ft_putstr(char *s, t_format *format);
size_t	ft_putnbr_u(unsigned int n, t_format *format);
size_t	ft_putnbr(int n);
size_t	ft_puthex(unsigned int n, t_format *format);
size_t	ft_putptr(unsigned long int n);
size_t	ft_putptr_pad(unsigned long int n, t_format format);
size_t	ft_ptrsize(unsigned long int n);
size_t	nbr_dig(int n);

#endif
