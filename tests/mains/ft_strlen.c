#include <stdio.h>

int	ft_strlen(char *str);

int	main(void)
{
	printf("[hello] -> %d  (esp 5)\n", ft_strlen("hello"));
	printf("[] -> %d  (esp 0)\n", ft_strlen(""));
	printf("[a b\\tc] -> %d  (esp 5)\n", ft_strlen("a b\tc"));
	return (0);
}
