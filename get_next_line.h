# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif 

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1,const char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_free(char *bucket, char *spon);

# endif