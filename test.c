#include <stdio.h>

int	main(void)
{
	int	number = -42;
	printf("Hex:\n");
	printf("%x \n", number);
	printf("%-6x \n", number);
	printf("%010x \n", number);
	printf("%-#10x \n", number);
	printf("%#x \n", number);
	printf("%*x \n", 5, number);

//	char	*str = "Hello World";
//	printf("%s \n", str);
//	printf("%4s \n", str);
//	printf("%.4s \n", str);
//
//	char	*str1 = "Hi";
//	printf("%s \n", str1);
//	printf("%4s \n", str1);
//	printf("%.4s \n", str1);
//
//	char	*str2 = "Hello";
//	printf("%s \n", str2);
//	printf("%5.4s \n", str2);
//	printf("%4.5s \n", str2);
}
