#include <stdio.h>

char	**ft_split(char *str);

static void	t(char *in)
{
	char	**r;
	int		i;

	r = ft_split(in);
	printf("[%s] ->", in);
	i = 0;
	while (r[i])
	{
		printf(" <%s>", r[i]);
		i++;
	}
	printf("   (%d palavras)\n", i);
}

int	main(void)
{
	t("hello world");
	t("  espacos  a  mais  ");
	t("tab\te\nnewline");
	t("");
	t("     ");
	t("uma");
	return (0);
}
