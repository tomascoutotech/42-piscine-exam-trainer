#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	put_hex_byte(unsigned char b)
{
	char	*digits;

	digits = "0123456789abcdef";
	ft_putchar(digits[b / 16]);
	ft_putchar(digits[b % 16]);
}

void	print_memory(const void *addr, size_t size)
{
	const unsigned char	*p;
	size_t				i;
	size_t				j;

	p = addr;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < 16)
		{
			if (i + j < size)
				put_hex_byte(p[i + j]);
			else
				write(1, "  ", 2);
			if (j % 2 == 1)
				ft_putchar(' ');
			j++;
		}
		j = 0;
		while (j < 16 && i + j < size)
		{
			if (p[i + j] >= 32 && p[i + j] <= 126)
				ft_putchar(p[i + j]);
			else
				ft_putchar('.');
			j++;
		}
		ft_putchar('\n');
		i = i + 16;
	}
}
