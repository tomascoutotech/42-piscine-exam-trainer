#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	char	*s;
	long	n;
	int		len;
	int		neg;

	n = nbr;
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
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
		n = -n;
	while (len-- > neg)
	{
		s[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		s[0] = '-';
	return (s);
}
