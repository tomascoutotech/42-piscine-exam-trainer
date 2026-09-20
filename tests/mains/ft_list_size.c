#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

int	ft_list_size(t_list *begin_list);

int	main(void)
{
	t_list	a;
	t_list	b;
	t_list	c;

	a.data = "1";
	b.data = "2";
	c.data = "3";
	a.next = &b;
	b.next = &c;
	c.next = NULL;
	printf("%d  (esp 3)\n", ft_list_size(&a));
	printf("%d  (esp 1)\n", ft_list_size(&c));
	printf("%d  (esp 0, lista vazia)\n", ft_list_size(NULL));
	return (0);
}
