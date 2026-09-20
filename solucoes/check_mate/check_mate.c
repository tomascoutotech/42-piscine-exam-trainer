#include <unistd.h>
#include "check_mate.h"

int	is_piece(char c)
{
	return (c == 'P' || c == 'B' || c == 'R' || c == 'Q');
}

int	ray(char **b, int n, t_pos k, t_pos d)
{
	int	r;
	int	c;

	r = k.r + d.r;
	c = k.c + d.c;
	while (r >= 0 && r < n && c >= 0 && c < n)
	{
		if (is_piece(b[r][c]))
		{
			if (d.r == 0 || d.c == 0)
				return (b[r][c] == 'R' || b[r][c] == 'Q');
			return (b[r][c] == 'B' || b[r][c] == 'Q');
		}
		r = r + d.r;
		c = c + d.c;
	}
	return (0);
}

int	in_check(char **b, int n, t_pos k)
{
	int		dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
	int		dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};
	t_pos	d;
	int		i;

	i = 0;
	while (i < 8)
	{
		d.r = dr[i];
		d.c = dc[i];
		if (ray(b, n, k, d))
			return (1);
		i++;
	}
	if (k.r > 0 && k.c > 0 && b[k.r - 1][k.c - 1] == 'P')
		return (1);
	if (k.r > 0 && k.c + 1 < n && b[k.r - 1][k.c + 1] == 'P')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**b;
	int		n;
	t_pos	k;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	b = argv + 1;
	n = argc - 1;
	k.r = 0;
	while (k.r < n)
	{
		k.c = 0;
		while (b[k.r][k.c])
		{
			if (b[k.r][k.c] == 'K' && in_check(b, n, k))
			{
				write(1, "Success\n", 8);
				return (0);
			}
			k.c++;
		}
		k.r++;
	}
	write(1, "Fail\n", 5);
	return (0);
}
