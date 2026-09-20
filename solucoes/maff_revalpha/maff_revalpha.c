#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	int	i;

	i = 0;
	while (i < 26)
	{
		if (i % 2 == 0)
			ft_putchar('z' - i);
		else
			ft_putchar('Z' - i);
		i++;
	}
	ft_putchar('\n');
	return (0);
}
