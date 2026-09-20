#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		n;
	char	c;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			c = argv[1][i];
			n = 1;
			if (c >= 'a' && c <= 'z')
				n = c - 'a' + 1;
			else if (c >= 'A' && c <= 'Z')
				n = c - 'A' + 1;
			j = 0;
			while (j++ < n)
				ft_putchar(c);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
