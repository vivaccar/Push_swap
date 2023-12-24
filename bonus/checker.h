#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <limits.h>
# include "../Libft/libft.h"
# include "../push_swap.h" 

char	*get_next_line(int fd);
char	*ft_read(int fd, char *text);
char	*ft_delete(char *text);
void	input_error(char *op, t_stack **stack_a, t_stack **stack_b);
void	do_ops(char *op, t_stack **stack_a, t_stack **stack_b);
void	read_commands(t_stack **stack_a);

#endif