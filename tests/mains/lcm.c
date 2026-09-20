#include <stdio.h>

unsigned int	lcm(unsigned int a, unsigned int b);

int	main(void)
{
	printf("%u  (esp 12)\n", lcm(4, 6));
	printf("%u  (esp 21)\n", lcm(3, 7));
	printf("%u  (esp 5)\n", lcm(5, 5));
	printf("%u  (esp 0, com zero)\n", lcm(0, 5));
	printf("%u  (esp 0, com zero)\n", lcm(5, 0));
	printf("%u  (esp 4000000000: a*b transbordaria, a/x*b nao)\n",
		lcm(2000000000u, 4000000000u));
	return (0);
}
