#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <limits.h>
# include "../Libft/libft.h"
# include "../push_swap.h" 

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 3
#endif

char	*get_next_line(int fd);
char	*ft_strchr_2(char *s, int c);
char	*ft_read(int fd, char *text);
char	*ft_delete(char *text);
char	*ft_extractline(char *text);

#endif