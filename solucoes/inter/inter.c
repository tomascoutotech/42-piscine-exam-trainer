#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	seen[256];

	i = 0;
	while (i < 256)
		seen[i++] = 0;
	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			j = 0;
			while (argv[2][j] && argv[2][j] != argv[1][i])
				j++;
			if (argv[2][j] && !seen[(unsigned char)argv[1][i]])
			{
				ft_putchar(argv[1][i]);
				seen[(unsigned char)argv[1][i]] = 1;
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
