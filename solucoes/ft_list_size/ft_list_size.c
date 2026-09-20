#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	n;

	n = 0;
	while (begin_list)
	{
		n++;
		begin_list = begin_list->next;
	}
	return (n);
}
