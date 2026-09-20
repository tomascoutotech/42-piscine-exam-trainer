#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int	main(int argc, char **argv)
{
	int	n;
	int	i;

	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	n = 0;
	i = 0;
	while (argv[1][i] >= '0' && argv[1][i] <= '9')
	{
		n = n * 10 + (argv[1][i] - '0');
		i++;
	}
	i = 1;
	while (i <= 9)
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(n);
		write(1, " = ", 3);
		ft_putnbr(i * n);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
