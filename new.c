#include <stdio.h>
#include "libft/libft.h"
#include "includes/ft_printf_bonus.h"

int	main(void)
{
	//  Extra test                                                                            
	//	Percent 
	printf("-----== Print %% ==------\n");
	printf("ORI:||%%||\n");
	ft_printf("FT_:||%%||\n");
	printf("-----------\n");
	printf("ORI:||%5%||\n");
	ft_printf("FT_:||%5%||\n");
	printf("-----------\n");
	// Strings
	printf("-----== Print str with flags ==------\n");
	printf("ORI:||%.09s||\n", (char *)NULL);
	ft_printf("FT_:||%.09s||\n", (char *)NULL);
	printf("-----------\n");
	printf("ORI:||%3.s||\n", (char *)NULL);
	ft_printf("FT_:||%3.s||\n", (char *)NULL);
	printf("-----------\n");
	printf("ORI:||%3.6s||\n", (char *)NULL);
	ft_printf("FT_:||%3.6s||\n", (char *)NULL);
	printf("-----------\n");
	printf("ORI:||%7.5s||\n", "bombastic");
	ft_printf("FT_:||%7.5s||\n", "bombastic");
	printf("-----------\n");
	printf("ORI:||%-7.5s||\n", "tubular");
	ft_printf("FT_:||%-7.5s||\n", "tubular");
	printf("-----------\n");
	// Integers
	printf("-----== Print int with flags ==------\n");
	printf("ORI:||t1 %40.0d||\n", 10);
	ft_printf("FT_:||t1 %40.0d||\n", 10);
	printf("-----------\n");
	printf("ORI:||%5.0i||\n", 0);
	ft_printf("FT_:||%5.0i||\n", 0);
	printf("-----------\n");
	printf("ORI:||%i||\n", INT_MAX);
	ft_printf("FT_:||%i||\n", INT_MAX);
	printf("-----------\n");
	//	Character
	printf("-----== Print char with flags ==------\n");
	printf("ORI:||%.c||\n", 'a');
	ft_printf("FT_:||%.c||\n", 'a');
	printf("-----------\n");
	printf("ORI:||%--172c||\n", 108);
	ft_printf("FT_:||%--172c||\n", 108);
	printf("-----------\n");
}
