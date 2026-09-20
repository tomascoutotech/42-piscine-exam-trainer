#include <stdlib.h>

int	is_sep(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	count_words(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i]))
			i++;
		if (str[i])
			n++;
		while (str[i] && !is_sep(str[i]))
			i++;
	}
	return (n);
}

char	*word_dup(char *str, int start, int end)
{
	char	*w;
	int		i;

	w = malloc(sizeof(char) * (end - start + 1));
	if (!w)
		return (0);
	i = 0;
	while (start < end)
		w[i++] = str[start++];
	w[i] = '\0';
	return (w);
}

char	**ft_split(char *str)
{
	char	**tab;
	int		i;
	int		j;
	int		start;

	tab = malloc(sizeof(char *) * (count_words(str) + 1));
	if (!tab)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i]))
			i++;
		start = i;
		while (str[i] && !is_sep(str[i]))
			i++;
		if (i > start)
			tab[j++] = word_dup(str, start, i);
	}
	tab[j] = 0;
	return (tab);
}
