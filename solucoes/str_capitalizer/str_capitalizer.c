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
	int		a;
	int		i;
	int		start;
	char	c;

	a = 1;
	while (a < argc)
	{
		i = 0;
		start = 1;
		while (argv[a][i])
		{
			c = argv[a][i];
			if (c >= 'A' && c <= 'Z')
				c = c + 32;
			if (start && c >= 'a' && c <= 'z')
				c = c - 32;
			start = is_space(argv[a][i]);
			ft_putchar(c);
			i++;
		}
		ft_putchar('\n');
		a++;
	}
	if (argc == 1)
		ft_putchar('\n');
	return (0);
}
