#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	main(int argc, char **argv)
{
	int	i;
	int	first;

	if (argc == 2)
	{
		i = 0;
		first = 1;
		while (argv[1][i])
		{
			while (is_space(argv[1][i]))
				i++;
			if (argv[1][i] && !first)
				ft_putchar(' ');
			while (argv[1][i] && !is_space(argv[1][i]))
			{
				ft_putchar(argv[1][i]);
				i++;
				first = 0;
			}
		}
	}
	ft_putchar('\n');
	return (0);
}
