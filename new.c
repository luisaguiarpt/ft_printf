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
	// Hex	
	printf("-----== Print char with flags ==------\n");
	int a = printf("ORI:||%#x||\n", 0);
	printf("%d\n", a);
	int b = ft_printf("FT_:||%#x||\n", 0);
	printf("%d\n", b);
	printf("-----------\n");
	a = printf("ORI:||%#x||\n", LONG_MIN);
	printf("%d\n", a);
	b = ft_printf("FT_:||%#x||\n", LONG_MIN);
	printf("%d\n", b);
	printf("-----------\n");
	// Integers
	printf("-----== Print int with flags ==------\n");
	a = printf("ORI:||t1 % d||\n", 0);
	printf("%d\n", a);
	b = ft_printf("FT_:||t1 % d||\n", 0);
	printf("%d\n", b);
	printf("-----------\n");
	a = printf("ORI:||% i||\n", LONG_MIN);
	printf("%d\n", a);
	b = ft_printf("FT_:||% i||\n", LONG_MIN);
	printf("%d\n", b);
	printf("-----------\n");
	a = printf("ORI:||%+i||\n", 0);
	printf("%d\n", a);
	b = ft_printf("FT_:||%+i||\n", 0);
	printf("%d\n", b);
	printf("-----------\n");
	//	Character
	printf("-----== Print char with flags ==------\n");
	a = printf("ORI:||%-2c||\n", '0');
	printf("%d\n", a);
	b = ft_printf("FT_:||%-2c||\n", '0');
	printf("%d\n", b);
	printf("-----------\n");
	printf("ORI:||%#-3c||\n", '0' - 256);
	ft_printf("FT_:||%#-3c||\n", '0' - 256);
	printf("-----------\n");
	//	Extra	
	printf("-----== Print with flags ==------\n");
	a = printf("ORI:||%5%||\n");
	printf("%d\n", a);
	b = ft_printf("FT_:||%5%||\n");
	printf("%d\n", b);
	printf("-----------\n");
	a = printf("ORI:||%-5%||\n");
	printf("%d\n", a);
	b = ft_printf("FT_:||%-5%||\n");
	printf("%d\n", b);
	printf("-----------\n");
	a = printf("ORI:||%p||\n", NULL);
	printf("%d\n", a);
	b = ft_printf("FT_:||%p||\n", NULL);
	printf("%d\n", b);
	printf("-----------\n");
	a = printf("ORI:||%15p||\n", NULL);
	printf("%d\n", a);
	b = ft_printf("FT_:||%15p||\n", NULL);
	printf("%d\n", b);
	printf("-----------\n");
}
