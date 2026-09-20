#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

static int	cmp(char *a, char *b)
{
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return (*a - *b);
}

static t_list	*push(t_list *head, char *s)
{
	t_list	*n;

	n = malloc(sizeof(t_list));
	n->data = s;
	n->next = head;
	return (n);
}

static void	mostra(t_list *l)
{
	while (l)
	{
		printf("<%s>", (char *)l->data);
		l = l->next;
	}
	printf("\n");
}

int	main(void)
{
	t_list	*l;

	l = NULL;
	l = push(l, "d");
	l = push(l, "b");
	l = push(l, "c");
	l = push(l, "b");
	l = push(l, "a");
	mostra(l);
	ft_list_remove_if(&l, "b", &cmp);
	printf("sem b (os DOIS): ");
	mostra(l);
	ft_list_remove_if(&l, "a", &cmp);
	printf("sem a (era o 1o): ");
	mostra(l);
	return (0);
}
