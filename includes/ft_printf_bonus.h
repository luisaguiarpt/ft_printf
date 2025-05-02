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

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_format
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

// Main
int		ft_printf(const char *str, ...);
// Main utils
size_t	get_function(t_format *format, char c, va_list args);
void	check_error(t_format *format);
int		init_flags(t_format **ptr);
// Parsers
void	get_flags(char c, t_format *format);
int		parse_str(const	char *str, t_format *format);
int		get_type(char c, t_format *format);
int		get_nbr(const char *str, t_format *format, char min_max);
// Parser utils
int		is_flag(char c);
int		is_max(const char *str);
int		is_type(char c);
// Print utils
size_t	putchar_format(char c, t_format *format);
size_t	putstr_format(char *s, t_format *format);
size_t	putnbr_u_format(unsigned int n, t_format *format);
size_t	putnbr_format(int n, t_format *format);
size_t	puthex_format(unsigned int n, t_format *format);
size_t	putptr_format(unsigned long int n, t_format *format);
// General utils
size_t	abs_nbr_dig(int n);
size_t	u_nbr_dig(unsigned int n);
size_t	hex_nbr_dig(unsigned int n);
//size_t	nbr_dig(int n);

#endif
