#include <stdio.h>

void	ft_swap(int *a, int *b);

int	main(void)
{
	int	x;
	int	y;

	x = 1;
	y = 2;
	ft_swap(&x, &y);
	printf("x=%d y=%d  (esp x=2 y=1)\n", x, y);
	ft_swap(&x, &x);
	printf("x=%d  (esp 2, trocar consigo proprio)\n", x);
	return (0);
}
