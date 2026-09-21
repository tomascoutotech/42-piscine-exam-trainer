#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);

static int	sinal(int n)
{
	if (n > 0)
		return (1);
	if (n < 0)
		return (-1);
	return (0);
}

static void	t(char *a, char *b)
{
	// do strcmp do sistema compara-se o SINAL, nao o valor: a glibc devolve a
	// diferenca (99) e a libc do Windows devolve 1. As duas estao certas -- o
	// man so promete o sinal. O teu valor e que aparece inteiro.
	printf("[%s] vs [%s] -> teu %4d | real %2d\n",
		a, b, ft_strcmp(a, b), sinal(strcmp(a, b)));
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
