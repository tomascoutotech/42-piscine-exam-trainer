#include <unistd.h>
#include <stdlib.h>
#include "brainfuck.h"

void	jump_fwd(char *code, int *pc)
{
	int	depth;

	depth = 1;
	while (depth > 0 && code[*pc])
	{
		(*pc)++;
		if (code[*pc] == '[')
			depth++;
		else if (code[*pc] == ']')
			depth--;
	}
}

void	jump_back(char *code, int *pc)
{
	int	depth;

	depth = 1;
	while (depth > 0 && *pc > 0)
	{
		(*pc)--;
		if (code[*pc] == ']')
			depth++;
		else if (code[*pc] == '[')
			depth--;
	}
}

int	main(int argc, char **argv)
{
	char	*mem;
	char	*code;
	int		p;
	int		pc;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	mem = malloc(2048);
	if (!mem)
		return (1);
	p = 0;
	while (p < 2048)
		mem[p++] = 0;
	p = 0;
	pc = 0;
	code = argv[1];
	while (code[pc])
	{
		if (code[pc] == '>')
			p++;
		else if (code[pc] == '<')
			p--;
		else if (code[pc] == '+')
			mem[p]++;
		else if (code[pc] == '-')
			mem[p]--;
		else if (code[pc] == '.')
			write(1, &mem[p], 1);
		else if (code[pc] == '[' && mem[p] == 0)
			jump_fwd(code, &pc);
		else if (code[pc] == ']' && mem[p] != 0)
			jump_back(code, &pc);
		pc++;
	}
	free(mem);
	return (0);
}
