#include "get_next_line.h"

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

void	freee(void **ap)
{
	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	size;

	if (s1 && s2)
		size = (size_t)(ft_strlen((char*)s1) + ft_strlen((char*)s2));
	else if (s1)
		size = (size_t)(ft_strlen((char*)s1));
	else if (s2)
		size = (size_t)(ft_strlen((char*)s2));
	else
		return (NULL);
	if (!(result = (char *) malloc(sizeof(char) * size)))
		return (NULL);
	if (s1)
		result = ft_strcpy(result, (char*)s1);
	else
		result = ft_strcpy(result, (char*)s2);
	if (s1 && s2)
		result = ft_strcat(result, (char*)s2);
	return (result);
}

char			*ft_strchr(const char *s, int c)
{
    while (*s)
	{
		if (*s == c)
			return ((char*)s);
		++s;
	}
	if (c == '\0')
		return ((char*)s);
	return (0);
}