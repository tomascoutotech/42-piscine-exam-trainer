#include <stdio.h>
#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *));

static void	mostra(void *d)
{
	printf("<%s>", (char *)d);
}

int	main(void)
{
	t_list	a;
	t_list	b;
	t_list	c;

	a.data = "um";
	b.data = "dois";
	c.data = "tres";
	a.next = &b;
	b.next = &c;
	c.next = NULL;
	ft_list_foreach(&a, &mostra);
	printf("  (esp <um><dois><tres>)\n");
	ft_list_foreach(NULL, &mostra);
	printf("  (esp nada antes deste texto)\n");
	return (0);
}
