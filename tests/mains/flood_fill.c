#include <stdio.h>
#include "flood_fill.h"

static void	mostra(char **a)
{
	int	i;
	int	j;

	i = 0;
	while (a[i])
	{
		j = 0;
		while (a[i][j])
		{
			printf("%c ", a[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(void)
{
	char	l0[] = "11111111";
	char	l1[] = "10001001";
	char	l2[] = "10010001";
	char	l3[] = "10110001";
	char	l4[] = "11100001";
	char	*area[] = {l0, l1, l2, l3, l4, NULL};
	t_point	size = {8, 5};
	t_point	begin = {2, 2};

	mostra(area);
	flood_fill(area, size, begin);
	printf("\n");
	mostra(area);
	return (0);
}
