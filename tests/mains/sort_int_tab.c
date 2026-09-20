#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size);

static void	t(int *a, unsigned int n)
{
	unsigned int	i;

	sort_int_tab(a, n);
	i = 0;
	while (i < n)
	{
		printf("%d ", a[i]);
		i++;
	}
	printf("\n");
}

int	main(void)
{
	int	a[] = {5, 2, 9, 2, -3, 0, 7};
	int	b[] = {1};
	int	c[] = {3, 3, 3};

	t(a, 7);
	t(b, 1);
	t(c, 3);
	t(a, 0);
	printf("(a ultima linha vazia e o size 0)\n");
	return (0);
}
