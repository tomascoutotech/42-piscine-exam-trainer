#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int		a;
	int		i;
	char	seen[256];

	i = 0;
	while (i < 256)
		seen[i++] = 0;
	if (argc == 3)
	{
		a = 1;
		while (a <= 2)
		{
			i = 0;
			while (argv[a][i])
			{
				if (!seen[(unsigned char)argv[a][i]])
				{
					ft_putchar(argv[a][i]);
					seen[(unsigned char)argv[a][i]] = 1;
				}
				i++;
			}
			a++;
		}
	}
	ft_putchar('\n');
	return (0);
}
