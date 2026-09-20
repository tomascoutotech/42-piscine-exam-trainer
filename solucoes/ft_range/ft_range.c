#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*tab;
	int	len;
	int	step;
	int	i;

	step = 1;
	if (start > end)
		step = -1;
	len = (end - start) * step + 1;
	tab = malloc(sizeof(int) * len);
	if (!tab)
		return (0);
	i = 0;
	while (i < len)
	{
		tab[i] = start + i * step;
		i++;
	}
	return (tab);
}
