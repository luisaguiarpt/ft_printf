#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("-----ori-----\n");
	printf("%c\n", 'a');
	printf("-----ft-----\n");
	ft_printf("%c\n", 'a');
	printf("----------\n");
	printf("-----ori-----\n");
	printf("%i\n", 1);
	printf("-----ft-----\n");
	ft_printf("%i\n", 1);
	printf("----------\n");
	printf("%s\n", (char *)0);
	printf("----------\n");

	printf("-----ori-----\n");
	printf("%p\n", -1);
	printf("-----ft-----\n");
	ft_printf("%p\n", -1);
	printf("----------\n");
}
