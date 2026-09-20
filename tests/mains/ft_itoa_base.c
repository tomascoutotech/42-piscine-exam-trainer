#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa_base(int value, int base);

static void	t(int v, int b)
{
	char	*s;

	s = ft_itoa_base(v, b);
	printf("itoa_base(%11d, %2d) = %s\n", v, b, s);
	free(s);
}

int	main(void)
{
	t(42, 10);
	t(-42, 10);
	t(0, 10);
	t(255, 16);
	t(255, 2);
	t(6, 4);
	t(-42, 16);
	t(-2147483647 - 1, 10);
	return (0);
}
