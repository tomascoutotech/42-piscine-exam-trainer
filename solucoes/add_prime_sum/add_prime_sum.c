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

int	is_prime(int n)
{
	int	i;

	if (n < 2)
		return (0);
	i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	n;
	int	i;
	int	sum;

	i = 0;
	if (argc == 2)
		while (argv[1][i] >= '0' && argv[1][i] <= '9')
			i++;
	if (argc != 2 || i == 0 || argv[1][i] != '\0')
	{
		write(1, "0\n", 2);
		return (0);
	}
	n = 0;
	i = 0;
	while (argv[1][i])
		n = n * 10 + (argv[1][i++] - '0');
	sum = 0;
	i = 2;
	while (i <= n)
	{
		if (is_prime(i))
			sum = sum + i;
		i++;
	}
	ft_putnbr(sum);
	ft_putchar('\n');
	return (0);
}
