#include <stdio.h>

int	is_power_of_2(unsigned int n);

int	main(void)
{
	unsigned int	v[] = {0, 1, 2, 3, 4, 6, 8, 42, 1024, 2147483648u};
	int				i;

	i = 0;
	while (i < 10)
	{
		printf("%10u -> %d\n", v[i], is_power_of_2(v[i]));
		i++;
	}
	printf("esperado:  0 1 1 0 1 0 1 0 1 1\n");
	return (0);
}
