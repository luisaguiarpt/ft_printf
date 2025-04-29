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
	printf("%c\n", 'a');
	printf("-----ft-----\n");
	ft_printf("%c\n", 'a');
	printf("----------\n");
	printf("----------\n");
//
//	int	res1;
//	int	res2;
//	printf("-----ori-----\n");
//	res1 = printf("%p\n", (void *)-1);
//	printf("%i\n", res1);
//	printf("-----ft-----\n");
//	res2 = ft_printf("%p\n", (void *)-1);
//	printf("%i\n", res2);
//	printf("----------\n");
//	printf("Size of int *: %zu bytes\n", sizeof(int *));
//    printf("Size of char *: %zu bytes\n", sizeof(char *));
//    printf("Size of void *: %zu bytes\n", sizeof(void *));
	printf("----strings v ------\n");
	printf("%p", (void *)0);
	ft_printf("%p", 0);
	//printf("%-25c\n", 'a');
}
