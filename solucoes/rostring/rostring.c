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
	int	start;
	int	end;
	int	written;

	if (argc < 2)
	{
		ft_putchar('\n');
		return (0);
	}
	i = 0;
	while (is_space(argv[1][i]))
		i++;
	start = i;
	while (argv[1][i] && !is_space(argv[1][i]))
		i++;
	end = i;
	written = 0;
	while (argv[1][i])
	{
		while (is_space(argv[1][i]))
			i++;
		if (argv[1][i] && written)
			ft_putchar(' ');
		while (argv[1][i] && !is_space(argv[1][i]))
		{
			ft_putchar(argv[1][i]);
			written = 1;
			i++;
		}
	}
	if (written && end > start)
		ft_putchar(' ');
	while (start < end)
		ft_putchar(argv[1][start++]);
	ft_putchar('\n');
	return (0);
}
