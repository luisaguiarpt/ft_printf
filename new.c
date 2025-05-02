#include <stdio.h>
#include "includes/ft_printf_bonus.h"

int	main(void)
{
	//  Extra test                                                                            
	//	Percent 
	printf("-----== Print %% ==------\n");
	printf("ORI:||%%||\n");
	ft_printf("FT_:||%%||\n");
	printf("-----------\n");
	//printf("ORI:||%5%%||\n");
	ft_printf("FT_:||%5%||\n");
	printf("-----------\n");
	//	Character
	printf("-----== Print char with flags ==------\n");
	//printf("ORI:||%.c||\n", 'a');
	ft_printf("FT_:||%.c||\n", 'a');
	printf("-----------\n");
	// Strings
	printf("-----== Print str with flags ==------\n");
	//printf("ORI:||%-s||\n", (char *)NULL);
	ft_printf("FT_:||%-s||\n",(char *)NULL);
	printf("-----------\n");
}
