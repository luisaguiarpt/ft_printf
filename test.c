#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "includes/ft_printf_bonus.h"

int	main(void)
{
//	Char tests: only works with: - and min
	char	c = 'a';
	printf("-----begin char tests-----\n");
	printf("||%-c|| \n", c);
	ft_printf("||%-c|| \n", c);
	printf("||%-4c|| \n", c);
	ft_printf("||%-4c|| \n", c);
	printf("||%4c|| \n", c);
	ft_printf("||%4c|| \n", c);
	printf("||%-2c|| \n", c);
	ft_printf("||%-2c|| \n", c);
	printf("||%2c|| \n", c);
	ft_printf("||%2c|| \n", c);
	printf("-----end char tests-----\n");
//	Str tests: only works with: -, min, .
	printf("-----begin str tests-----\n");
	char	*str = "Hello";
	printf("||left-just||\n");
	//printf("ori||%-10.1s||\n", (char *)0);
	ft_printf("ft_||%-10.1s||\n", (char *)0);
	printf("ori||%-1.4s||\n", str);
	ft_printf("ft_||%-1.4s||\n", str);
	printf("ori||%-4.1s||\n", str);
	ft_printf("ft_||%-4.1s||\n", str);
	printf("||normal||\n");
	//printf("ori||%10s||\n", (char *)0);
	ft_printf("ft_||%10s||\n", (char *)0);
	printf("ori||%1.4s||\n", str);
	ft_printf("ft_||%1.4s||\n", str);
	printf("ori||%4.3s||\n", str);
	ft_printf("ft_||%4.3s||\n", str);
	printf("ori||%4.2s||\n", str);
	ft_printf("ft_||%4.2s||\n", str);
	printf("ori||%4.1s||\n", str);
	ft_printf("ft_||%4.1s||\n", str);
	printf("-----end str tests-----\n");
//	Ptr tests: works with: -, min
	printf("-----begin ptr tests-----\n");
	printf("ori||%p||\n", (void *)0);
	ft_printf("ft_||%p||\n", (void *)0);
	printf("|ori|%6p||\n", (void *)-10);
	ft_printf("ft_||%6p||\n", (void *)-10);
	printf("ori||%10p||\n", (void *)1234);
	ft_printf("ft_||%10p||\n", (void *)1234);
	printf("ori||%-10p||\n", (void *)-123456);
	ft_printf("ft_||%-10p||\n", (void *)-123456);
	printf("ori||%-16p||\n", (void *)INT_MAX);
	ft_printf("ft_||%-16p||\n", (void *)INT_MAX);
	printf("ori||%p||\n", (void *)INT_MIN);
	ft_printf("ft_||%p||\n", (void *)INT_MIN);
	printf("-----end ptr tests-----\n");

//	Unsigned tests: works with: -, 0, ., min
//	printf("||%1.7u||\n", 0);
//	printf("||%1.8u||\n", 1243);
//	printf("||%7.1u||\n", 1234);
//	printf("||%7.4u||\n", 1234);
//	printf("------------------\n");
//	printf("||%-7.5u||\n", 1234);
//	printf("||%09.7u||\n", 1234);
//	printf("||%-7.7u||\n", 1234);
//	printf("------------------\n");
//	printf("||%010.3u||\n", 123412);
//	printf("||%010.3u||\n", -121243);
//	printf("------------------\n");

//	int tests: works with:
	printf("ori||%1.7i||\n", 0);
	ft_printf("ft_||%1.7i||\n", 0);
	printf("ori||%1.8i||\n", 1243);
	ft_printf("ft_||%1.8i||\n", 1243);
	printf("ori||%9.6i||\n", -1234);
	ft_printf("ft_||%9.6i||\n", -1234);
	printf("ori||%7.5i||\n", 1234);
	ft_printf("ft_||%7.5i||\n", 1234);
	printf("------------------\n");
	printf("ori||%-7.5i||\n", 1234);
	ft_printf("ft_||%-7.5i||\n", 1234);
	printf("ori||%-9.7i||\n", 1234);
	ft_printf("ft_||%-9.7i||\n", 1234);
	printf("ori||%-7.7i||\n", -1234);
	ft_printf("ft_||%-7.7i||\n", -1234);
	printf("------------------\n");
	printf("ori||%10.3i||\n", 123412);
	ft_printf("ft_||%10.3i||\n", 123412);
//	printf("ori||%10.3i||\n", -121243);
//	ft_printf("ft_||%10.3i||\n", -121243);
	printf("------------------\n");

//	printf("------------------\n");
//	printf("%u \n", -1);
//	printf("%u \n", -13);
//	printf("%u \n", -2147483647);
}
