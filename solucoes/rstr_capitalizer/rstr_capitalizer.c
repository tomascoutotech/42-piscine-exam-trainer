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
	char	c;

	a = 1;
	while (a < argc)
	{
		i = 0;
		while (argv[a][i])
		{
			c = argv[a][i];
			if (c >= 'A' && c <= 'Z')
				c = c + 32;
			if (c >= 'a' && c <= 'z'
				&& (argv[a][i + 1] == '\0' || is_space(argv[a][i + 1])))
				c = c - 32;
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
