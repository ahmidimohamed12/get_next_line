#include "get_next_line.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
static char	*ft_strdup(const char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		++size;
	if (!(new = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*result;

	if (!s || !(result =(char *)malloc(len + 1)))
		return (NULL);
	result = ft_strncpy(result, (char*)s + start, len);
	return (result);
}

int	get_next_line(const int fd, char **line)
{
	static char	*c[4864];
	char		buffer[BUFF_SIZE + 1];
	char		*tmp;
	ssize_t		b;
	int			endl;

	if (fd < 0 || (!c[fd] && !(c[fd] = (char *) malloc(sizeof(char) * 1 )) || !line))
		return (-1);
	while (!ft_strchr(c[fd], '\n') && (b = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[b] = '\0';
		tmp = c[fd];
		c[fd] = ft_strjoin(c[fd], buffer);
		freee(&tmp);
	}
	if (b == -1 || !*(tmp = c[fd]))
		return (b == -1 ? -1 : 0);
	if ((endl = (ft_strchr(c[fd], '\n') > 0)))
		*line = ft_strsub(c[fd], 0, ft_strchr(c[fd], '\n') - c[fd]);
	else
		*line = ft_strdup(c[fd]);
	c[fd] = ft_strsub(c[fd], (unsigned int)(ft_strlen(*line) + endl),
			(size_t)(ft_strlen(c[fd]) - (ft_strlen(*line) + endl)));
	freee(&tmp);
	return (!(!c[fd] && !ft_strlen(*line)));
}

int main(int argc, char **argv)
{
	int fd = open(argv[1],O_RDONLY);
	printf("%d",fd);

}