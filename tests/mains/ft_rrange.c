#include <stdio.h>
#include <stdlib.h>

int	*ft_rrange(int start, int end);

static void	t(int a, int b, int n)
{
	int	*r;
	int	i;

	r = ft_rrange(a, b);
	printf("rrange(%d,%d) ->", a, b);
	i = 0;
	while (i < n)
	{
		printf(" %d", r[i]);
		i++;
	}
	printf("\n");
	free(r);
}

int	main(void)
{
	t(1, 3, 3);
	t(3, 1, 3);
	t(0, 0, 1);
	t(-2, 2, 5);
	return (0);
}
