#include <stdio.h>
#include "list.h"

int	cycle_detector(const t_list *list);

int	main(void)
{
	t_list	a;
	t_list	b;
	t_list	c;

	a.next = &b;
	b.next = &c;
	c.next = NULL;
	printf("%d  (esp 0, sem ciclo)\n", cycle_detector(&a));
	c.next = &a;
	printf("%d  (esp 1, ciclo ate ao inicio)\n", cycle_detector(&a));
	c.next = &b;
	printf("%d  (esp 1, laco que nao inclui o 1o no)\n", cycle_detector(&a));
	printf("%d  (esp 0, lista vazia)\n", cycle_detector(NULL));
	a.next = NULL;
	printf("%d  (esp 0, um so no)\n", cycle_detector(&a));
	a.next = &a;
	printf("%d  (esp 1, no que aponta para si)\n", cycle_detector(&a));
	return (0);
}
