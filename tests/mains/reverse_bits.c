#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet);

int	main(void)
{
	printf("%u  (esp 128, de 1)\n", reverse_bits(1));
	printf("%u  (esp 1, de 128)\n", reverse_bits(128));
	printf("%u  (esp 0)\n", reverse_bits(0));
	printf("%u  (esp 255)\n", reverse_bits(255));
	printf("%u  (esp 6, de 96)\n", reverse_bits(96));
	return (0);
}
