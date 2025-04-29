#include <stdio.h>
#include <unistd.h>
#include <limits.h>

//void	use_printf(void)
//{
//	printf("MARCELO\n");
//}

//void	put_str(str)
//{
//	while (s[i] && i < max)
//		i++;
//	while (min < i)
//		write(1, ' ', 1);
//}
int	main(void)
{
//	//Char tests: only works with: - and min
//	char	c = 'a';
//	printf("||%-c|| \n", c);
//	printf("||%-4c|| \n", c);
//	printf("||%4c|| \n", c);
//	printf("||%-2c|| \n", c);
//	printf("||%2c|| \n", c);
//
	//Str tests: only works with: -, min, .
//	char	*str = "Hello";
//	printf("||left-just||\n");
//	printf("||%-10.1s||\n", (char *)0);
//	printf("||%-1.4s||\n", str);
//	printf("||%-4.1s||\n", str);
//	printf("||%-4.1s||\n", str);
//	printf("||normal||\n");
//	printf("||%10s||\n", (char *)0);
//	printf("||%1.4s||\n", str);
//	printf("||%4.3s||\n", str);
//	printf("||%4.2s||\n", str);
//	printf("||%4.1s||\n", str);
//	printf("------------------\n");
//
//	ptr tests: works with: -, min
//	printf("Ptr:\n");
//	printf("||%p||\n", (void *)0);
//	printf("||%6p||\n", (void *)-10);
//	printf("||%10p||\n", (void *)1234);
//	printf("||%-10p||\n", (void *)-123456);
//	printf("||%-16p||\n", (void *)INT_MAX);
//	printf("||%p||\n", (void *)INT_MIN);
//	printf("-----------------------\n");

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
	printf("||%1.7i||\n", 0);
	printf("||%1.8i||\n", 1243);
	printf("||%9.6i||\n", -1234);
	printf("||%7.5i||\n", 1234);
	printf("------------------\n");
	printf("||%-7.5i||\n", 1234);
	printf("||%-9.7i||\n", 1234);
	printf("||%-7.7i||\n", -1234);
	printf("------------------\n");
	printf("||%010.3i||\n", 123412);
	printf("||%010.3i||\n", -121243);
	printf("------------------\n");

//	printf("------------------\n");
//	printf("%u \n", -1);
//	printf("%u \n", -13);
//	printf("%u \n", -2147483647);
}
