#include <stdio.h>

void	ft_putstr(char *str);

int	main(void)
{
	setbuf(stdout, NULL);
	ft_putstr("hello");
	printf("|\n");
	ft_putstr("");
	printf("|  (esp so a barra)\n");
	return (0);
}
