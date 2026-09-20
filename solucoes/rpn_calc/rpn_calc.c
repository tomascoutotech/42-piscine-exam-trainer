#include <stdio.h>
#include <stdlib.h>
#include "rpn_calc.h"

int	tok_len(char *s, int i)
{
	int	n;

	n = 0;
	while (s[i + n] && s[i + n] != ' ')
		n++;
	return (n);
}

int	is_number(char *s, int i)
{
	int	n;
	int	k;

	n = tok_len(s, i);
	if (n == 0)
		return (0);
	k = 0;
	if (s[i] == '-' && n > 1)
		k = 1;
	while (k < n)
	{
		if (s[i + k] < '0' || s[i + k] > '9')
			return (0);
		k++;
	}
	return (1);
}

int	is_operator(char *s, int i)
{
	if (tok_len(s, i) != 1)
		return (0);
	return (s[i] == '+' || s[i] == '-' || s[i] == '*'
		|| s[i] == '/' || s[i] == '%');
}

int	apply(int a, int b, char op, int *err)
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (b == 0)
	{
		*err = 1;
		return (0);
	}
	if (op == '/')
		return (a / b);
	return (a % b);
}

int	main(int argc, char **argv)
{
	int		stack[512];
	int		top;
	int		i;
	int		err;

	err = 0;
	top = 0;
	i = 0;
	if (argc != 2)
		err = 1;
	while (!err && argv[1][i])
	{
		while (argv[1][i] == ' ')
			i++;
		if (!argv[1][i])
			break ;
		if (is_number(argv[1], i) && top < 512)
			stack[top++] = atoi(&argv[1][i]);
		else if (is_operator(argv[1], i) && top >= 2)
		{
			stack[top - 2] = apply(stack[top - 2], stack[top - 1],
					argv[1][i], &err);
			top--;
		}
		else
			err = 1;
		i = i + tok_len(argv[1], i);
	}
	if (err || top != 1)
		printf("Error\n");
	else
		printf("%d\n", stack[0]);
	return (0);
}
