#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int		i;
	char	c;

	i = 7;
	while (i >= 0)
	{
		c = ((octet >> i) & 1) + '0';
		write(1, &c, 1);
		i--;
	}
}
