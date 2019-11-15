
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include <unistd.h>
# include <fcntl.h>
#include <stdio.h>
# include <stdlib.h>

int					get_next_line(const int fd, char **line);
int ft_strlen(char *s);
char			*ft_strchr(const char *s, int c);
void    freee(void **p);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t n);
#endif
