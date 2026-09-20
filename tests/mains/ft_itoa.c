#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int nbr);

static void	t(int n)
{
	char	*s;

	s = ft_itoa(n);
	printf("%12d -> [%s]\n", n, s);
	free(s);
}

int	main(void)
{
	t(0);
	t(1);
	t(-1);
	t(42);
	t(-42);
	t(100);
	t(2147483647);
	t(-2147483647 - 1);
	return (0);
}
