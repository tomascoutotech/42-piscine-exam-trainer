#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	put_hex(int n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		put_hex(n / 16);
	ft_putchar(base[n % 16]);
}

int	main(int argc, char **argv)
{
	int	n;
	int	i;

	if (argc == 2)
	{
		n = 0;
		i = 0;
		while (argv[1][i] >= '0' && argv[1][i] <= '9')
		{
			n = n * 10 + (argv[1][i] - '0');
			i++;
		}
		put_hex(n);
	}
	ft_putchar('\n');
	return (0);
}
