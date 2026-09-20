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
			if (c == 'z')
				c = 'a';
			else if (c == 'Z')
				c = 'A';
			else if ((c >= 'a' && c < 'z') || (c >= 'A' && c < 'Z'))
				c = c + 1;
			ft_putchar(c);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
