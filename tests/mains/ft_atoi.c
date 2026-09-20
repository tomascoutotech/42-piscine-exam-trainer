#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str);

static void	t(const char *s)
{
	printf("[%s] -> teu %12d | real %12d\n", s, ft_atoi(s), atoi(s));
}

int	main(void)
{
	t("42");
	t("-42");
	t("   \t\n  42");
	t("+42");
	t("--42");
	t("---42");
	t("42abc");
	t("abc42");
	t("");
	t("2147483647");
	return (0);
}
