#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src);

int	main(void)
{
	char	origem[] = "hello";
	char	*copia;

	copia = ft_strdup(origem);
	origem[0] = 'X';
	printf("copia=[%s] origem=[%s]  (a copia tem de ficar hello)\n",
		copia, origem);
	printf("enderecos diferentes: %d  (esp 1)\n", copia != origem);
	free(copia);
	copia = ft_strdup("");
	printf("[%s] vazio ok\n", copia);
	free(copia);
	return (0);
}
