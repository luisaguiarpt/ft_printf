#include "../includes/ft_printf_bonus.h"

size_t	pos_diff_ui(size_t a, size_t b)
{
	long int	la;
	long int	lb;
	long int	diff;

	la = (long int)a;
	lb = (long int)b;
	diff = la - lb;
	if (diff >= 0)
		return ((size_t)diff);
	else
		return (0);
}
