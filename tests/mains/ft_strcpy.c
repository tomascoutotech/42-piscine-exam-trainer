#include <stdio.h>

char	*ft_strcpy(char *s1, char *s2);

int	main(void)
{
	char	dest[32];

	dest[0] = 'X';
	dest[5] = 'X';
	printf("[%s]  (esp hello)\n", ft_strcpy(dest, "hello"));
	printf("dest[5] = %d  (esp 0, o terminador)\n", dest[5]);
	printf("[%s]  (esp vazio)\n", ft_strcpy(dest, ""));
	return (0);
}
