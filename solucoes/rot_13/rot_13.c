#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int		i;
	char	c;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			c = argv[1][i];
			if (c >= 'a' && c <= 'z')
				c = 'a' + (c - 'a' + 13) % 26;
			else if (c >= 'A' && c <= 'Z')
				c = 'A' + (c - 'A' + 13) % 26;
			ft_putchar(c);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
