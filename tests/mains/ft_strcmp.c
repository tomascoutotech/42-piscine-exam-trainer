#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);

static void	t(char *a, char *b)
{
	printf("[%s] vs [%s] -> teu %4d | real %4d\n",
		a, b, ft_strcmp(a, b), strcmp(a, b));
}

int	main(void)
{
	t("abc", "abc");
	t("abc", "abd");
	t("abd", "abc");
	t("abc", "ab");
	t("ab", "abc");
	t("", "");
	t("\xff", "a");
	return (0);
}
