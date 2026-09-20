#ifndef CHECK_MATE_H
# define CHECK_MATE_H

typedef struct s_pos
{
	int	r;
	int	c;
}	t_pos;

int	is_piece(char c);
int	ray(char **b, int n, t_pos k, t_pos d);
int	in_check(char **b, int n, t_pos k);

#endif
