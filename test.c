#include <stdio.h>
#include <unistd.h>

void	use_printf(void)
{
	printf("MARCELO\n");
}

void	put_str(str)
{
	while (s[i] && i < max)
		i++;
	while (min < i)
		write(1, ' ', 1);
}
int	main(void)
{
//	int	number = -42;
//	printf("Hex:\n");
//	printf("%x \n", number);
//	printf("%-6x \n", number);
//	printf("%010x \n", number);
//	printf("%-#10x \n", number);
//	printf("%#x \n", number);
//	printf("%*x \n", 5, number);

	char	*str = "Hello";
	use_printf();
	printf("%s\n", str);
	printf("%1.4s\n", str);
	printf("%4.1s\n", str);
	printf("------------------\n");
	write(1, "M", 1);
	write(1, " ", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);

	printf("------------------\n");
	char	*str1 = "He";
	printf("%s\n", str1);
	printf("%1.4s\n", str1);
	printf("%4.1s\n", str1);

	printf("------------------\n");
//	char	*str2 = "Hello";
//	printf("%s \n", str2);
//	printf("%5.4s \n", str2);
//	printf("%4.5s \n", str2);
}
