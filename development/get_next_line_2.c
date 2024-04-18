#include "get_next_line.h"

// Increasing the buffer size 
// Possibily not a good approach because is designed to change the buffer 
// size

static	char	*ft_upgrade(char *buffer, int bytes_read)
{
	char	*tmp;
	int	i;

	tmp = (char *)malloc((BUFFER_SIZE + bytes_read + 1) * sizeof(char));
	if (tmp == NULL)
	{
		free(buffer);
		return (NULL);
	}
	i = 0;
	while (i < bytes_read)
	{
		tmp[i] = buffer[i];
		i++;
	}
	free(buffer);
	return (tmp);
}

char	*ft_get_next_line(int fd)
{
	static char	*text;
	char	*line;
	int	bytes_read;
	char	*tmp;
	int	i;

	line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (line == NULL)
	{
		return (NULL);
	}
	i = 0;
	while ((bytes_read = read(fd, line + 1, 1)) > 0)
	{
		if (line[i] == '\n')
		{
			line[i + 1] = '\0';
			text = strdup(line);
			free(line);
			return (text);
		}
		i++;
		if (i >= BUFFER_SIZE)
		{
			tmp = ft_upgrade(line, i);
			line = tmp;
		}
	}
	return (NULL);
}

int	main(void)
{
	int	fd;
	char	*text;

	fd = open("42Support.txt", O_RDONLY);
	while((text = ft_get_next_line(fd)))
	{
		printf("%s", text);
	}
	return (0);
}
