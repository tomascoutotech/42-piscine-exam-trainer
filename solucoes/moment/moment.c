#include <stdlib.h>

int	put_nb(char *dst, unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
		i = put_nb(dst, n / 10);
	dst[i] = '0' + (n % 10);
	return (i + 1);
}

int	copy(char *dst, int i, char *src)
{
	int	j;

	j = 0;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	return (i);
}

char	*unit_name(unsigned int d, unsigned int *val)
{
	*val = d;
	if (d < 60)
		return ("second");
	*val = d / 60;
	if (d < 3600)
		return ("minute");
	*val = d / 3600;
	if (d < 86400)
		return ("hour");
	*val = d / 86400;
	if (d < 2592000)
		return ("day");
	*val = d / 2592000;
	return ("month");
}

char	*moment(unsigned int duration)
{
	char			*res;
	char			*unit;
	unsigned int	val;
	int				i;

	unit = unit_name(duration, &val);
	res = malloc(sizeof(char) * 32);
	if (res == NULL)
		return (NULL);
	i = put_nb(res, val);
	res[i] = ' ';
	i = copy(res, i + 1, unit);
	if (val != 1)
	{
		res[i] = 's';
		i++;
	}
	i = copy(res, i, " ago.");
	res[i] = '\0';
	return (res);
}
