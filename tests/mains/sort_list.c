#include <stdio.h>
#include <stdlib.h>
#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int));

static int	ascendente(int a, int b)
{
	return (a <= b);
}

static int	descendente(int a, int b)
{
	return (a >= b);
}

static t_list	*push(t_list *head, int v)
{
	t_list	*n;

	n = malloc(sizeof(t_list));
	n->data = v;
	n->next = head;
	return (n);
}

static void	mostra(t_list *l)
{
	while (l)
	{
		printf("%d ", l->data);
		l = l->next;
	}
	printf("\n");
}

int	main(void)
{
	t_list	*l;

	l = NULL;
	l = push(l, 4);
	l = push(l, 1);
	l = push(l, 4);
	l = push(l, 3);
	l = push(l, 2);
	printf("asc:  ");
	mostra(sort_list(l, &ascendente));
	printf("desc: ");
	mostra(sort_list(l, &descendente));
	printf("NULL: %p\n", (void *)sort_list(NULL, &ascendente));
	return (0);
}
