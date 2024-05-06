# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
# endif 

char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buffer);
int		ft_clear_buffer(char *buffer);
int     ft_strlen(char *string);
char	*ft_cut_line(char *line);
# endif