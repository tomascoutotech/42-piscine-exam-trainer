#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	char			*s;
	char			*digits;
	unsigned int	n;
	int				len;
	int				neg;

	digits = "0123456789ABCDEF";
	neg = (base == 10 && value < 0);
	n = (unsigned int)value;
	if (neg)
		n = -(unsigned int)value;
	len = 1;
	while (n >= (unsigned int)base)
	{
		n = n / (unsigned int)base;
		len++;
	}
	len = len + neg;
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	s[len] = '\0';
	n = (unsigned int)value;
	if (neg)
		n = -(unsigned int)value;
	while (len-- > neg)
	{
		s[len] = digits[n % (unsigned int)base];
		n = n / (unsigned int)base;
	}
	if (neg)
		s[0] = '-';
	return (s);
}
