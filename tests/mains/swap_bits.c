#include <stdio.h>

unsigned char	swap_bits(unsigned char octet);

int	main(void)
{
	printf("0x%02x  (esp 0xba, de 0xab)\n", swap_bits(0xab));
	printf("0x%02x  (esp 0x00)\n", swap_bits(0x00));
	printf("0x%02x  (esp 0xff)\n", swap_bits(0xff));
	printf("0x%02x  (esp 0x01, de 0x10)\n", swap_bits(0x10));
	return (0);
}
