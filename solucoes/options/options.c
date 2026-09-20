#include <unistd.h>
#include "options.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}

void	put_flags(unsigned int n)
{
	int		i;
	char	c;

	i = 31;
	while (i >= 0)
	{
		c = ((n >> i) & 1) + '0';
		write(1, &c, 1);
		if (i % 8 == 0 && i != 0)
			write(1, " ", 1);
		i--;
	}
	write(1, "\n", 1);
}

void	usage(void)
{
	ft_putstr("options: abcdefghijklmnopqrstuvwxyz\n");
}

int	main(int argc, char **argv)
{
	unsigned int	flags;
	int				i;
	int				j;

	flags = 0;
	if (argc == 1)
	{
		usage();
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		j = 1;
		if (argv[i][0] != '-' || argv[i][1] == '\0')
		{
			ft_putstr("Invalid Option\n");
			return (0);
		}
		while (argv[i][j])
		{
			if (argv[i][j] < 'a' || argv[i][j] > 'z')
			{
				ft_putstr("Invalid Option\n");
				return (0);
			}
			if (argv[i][j] == 'h')
			{
				usage();
				return (0);
			}
			flags = flags | (1u << (argv[i][j] - 'a'));
			j++;
		}
		i++;
	}
	put_flags(flags);
	return (0);
}
