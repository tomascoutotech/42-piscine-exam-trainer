#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	n;
	int	d;
	int	first;

	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	n = atoi(argv[1]);
	if (n <= 1)
	{
		printf("%d\n", n);
		return (0);
	}
	first = 1;
	d = 2;
	while (n > 1)
	{
		while (n % d == 0)
		{
			if (!first)
				printf("*");
			printf("%d", d);
			first = 0;
			n = n / d;
		}
		d++;
	}
	printf("\n");
	return (0);
}
