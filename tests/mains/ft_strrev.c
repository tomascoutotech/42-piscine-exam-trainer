#include <stdio.h>

char	*ft_strrev(char *str);

int	main(void)
{
	char	a[] = "abcde";
	char	b[] = "abcd";
	char	c[] = "x";
	char	d[] = "";

	printf("[%s]  (esp edcba, impar)\n", ft_strrev(a));
	printf("[%s]  (esp dcba, par)\n", ft_strrev(b));
	printf("[%s]  (esp x)\n", ft_strrev(c));
	printf("[%s]  (esp vazio)\n", ft_strrev(d));
	return (0);
}
