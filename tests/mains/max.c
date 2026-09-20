#include <stdio.h>

int	max(int *tab, unsigned int len);

int	main(void)
{
	int	a[] = {3, 9, 2, 7};
	int	b[] = {-5, -2, -9};
	int	c[] = {42};

	printf("%d  (esp 9)\n", max(a, 4));
	printf("%d  (esp -2, so negativos)\n", max(b, 3));
	printf("%d  (esp 42)\n", max(c, 1));
	printf("%d  (esp 0, array vazio)\n", max(a, 0));
	return (0);
}
