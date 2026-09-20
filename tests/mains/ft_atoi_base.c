#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base);

int	main(void)
{
	printf("%d  (esp 255, ff base 16)\n", ft_atoi_base("ff", 16));
	printf("%d  (esp 255, FF maiusculas)\n", ft_atoi_base("FF", 16));
	printf("%d  (esp 5, 101 base 2)\n", ft_atoi_base("101", 2));
	printf("%d  (esp 5, 1012 para no 2)\n", ft_atoi_base("1012", 2));
	printf("%d  (esp -42 base 10)\n", ft_atoi_base("-42", 10));
	printf("%d  (esp 0, string invalida)\n", ft_atoi_base("zz", 16));
	return (0);
}
