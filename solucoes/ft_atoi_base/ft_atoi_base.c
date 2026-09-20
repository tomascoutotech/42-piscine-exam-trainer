int	value_of(char c, int base)
{
	int	v;

	v = -1;
	if (c >= '0' && c <= '9')
		v = c - '0';
	else if (c >= 'a' && c <= 'f')
		v = c - 'a' + 10;
	else if (c >= 'A' && c <= 'F')
		v = c - 'A' + 10;
	if (v >= base)
		return (-1);
	return (v);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sign;
	int	res;
	int	v;

	i = 0;
	sign = 1;
	res = 0;
	if (str[0] == '-')
	{
		sign = -1;
		i = 1;
	}
	v = value_of(str[i], str_base);
	while (v >= 0)
	{
		res = res * str_base + v;
		i++;
		v = value_of(str[i], str_base);
	}
	return (res * sign);
}
