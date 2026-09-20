#include <unistd.h>
#include "brackets.h"

int	is_open(char c)
{
	return (c == '(' || c == '[' || c == '{');
}

char	closer(char c)
{
	if (c == '(')
		return (')');
	if (c == '[')
		return (']');
	return ('}');
}

int	check(char *s)
{
	char	stack[4096];
	int		top;
	int		i;

	top = 0;
	i = 0;
	while (s[i])
	{
		if (is_open(s[i]) && top < 4096)
			stack[top++] = closer(s[i]);
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
		{
			if (top == 0 || stack[--top] != s[i])
				return (0);
		}
		i++;
	}
	return (top == 0);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (check(argv[i]))
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
		i++;
	}
	return (0);
}
