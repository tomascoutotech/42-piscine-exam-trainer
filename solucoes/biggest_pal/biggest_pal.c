#include <unistd.h>
#include "biggest_pal.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	grow(char *s, int l, int r, int *best)
{
	int	len;

	while (l >= 0 && s[r] && s[l] == s[r])
	{
		l--;
		r++;
	}
	l++;
	r--;
	len = r - l + 1;
	if (len >= best[1])
	{
		best[0] = l;
		best[1] = len;
	}
}

int	main(int argc, char **argv)
{
	int	best[2];
	int	len;
	int	i;

	if (argc == 2 && argv[1][0])
	{
		len = ft_strlen(argv[1]);
		best[0] = 0;
		best[1] = 1;
		i = 0;
		while (i < len)
		{
			grow(argv[1], i, i, best);
			grow(argv[1], i, i + 1, best);
			i++;
		}
		write(1, argv[1] + best[0], best[1]);
	}
	write(1, "\n", 1);
	return (0);
}
