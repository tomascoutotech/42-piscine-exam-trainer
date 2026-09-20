#include <unistd.h>

void	print_bits(unsigned char octet);

int	main(void)
{
	print_bits(2);
	write(1, "  (esp 00000010)\n", 17);
	print_bits(0);
	write(1, "  (esp 00000000)\n", 17);
	print_bits(255);
	write(1, "  (esp 11111111)\n", 17);
	print_bits(128);
	write(1, "  (esp 10000000)\n", 17);
	return (0);
}
