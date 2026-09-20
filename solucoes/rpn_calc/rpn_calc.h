#ifndef RPN_CALC_H
# define RPN_CALC_H

int	tok_len(char *s, int i);
int	is_number(char *s, int i);
int	is_operator(char *s, int i);
int	apply(int a, int b, char op, int *err);

#endif
