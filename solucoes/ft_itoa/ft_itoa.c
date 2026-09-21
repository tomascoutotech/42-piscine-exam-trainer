#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	char			*s;
	unsigned int	n;
	int				len;
	int				neg;

	neg = 0;
	n = nbr;
	if (nbr < 0)
	{
		neg = 1;
		n = -(unsigned int)nbr;
	}
	len = 1;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	len = len + neg;
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	s[len] = '\0';
	n = nbr;
	if (neg)
		n = -(unsigned int)nbr;
	while (len-- > neg)
	{
		s[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		s[0] = '-';
	return (s);
}
