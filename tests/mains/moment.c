#include <stdio.h>
#include <stdlib.h>

char	*moment(unsigned int duration);

static void	t(unsigned int d)
{
	char	*s;

	s = moment(d);
	printf("moment(%-8u) => %s\n", d, s);
	free(s);
}

int	main(void)
{
	t(0);
	t(1);
	t(59);
	t(60);
	t(65);
	t(120);
	t(3599);
	t(3600);
	t(86400);
	t(2591999);
	t(2592000);
	return (0);
}
