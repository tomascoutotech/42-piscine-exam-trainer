#include <unistd.h>

void	print_memory(const void *addr, size_t size);

int	main(void)
{
	int	tab[10] = {0, 23, 150, 255, 12, 16, 21, 42};

	print_memory(tab, sizeof(tab));
	write(1, "---\n", 4);
	print_memory("Hello!", 6);
	return (0);
}
