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
	int	j;
	int	end;
	int	written;

	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	i = 0;
	while (argv[1][i])
		i++;
	i--;
	written = 0;
	while (i >= 0)
	{
		while (i >= 0 && is_space(argv[1][i]))
			i--;
		end = i;
		while (i >= 0 && !is_space(argv[1][i]))
			i--;
		if (end > i)
		{
			if (written)
				ft_putchar(' ');
			written = 1;
			j = i + 1;
			while (j <= end)
				ft_putchar(argv[1][j++]);
		}
	}
	ft_putchar('\n');
	return (0);
}
