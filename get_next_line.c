// What ever we malloc explicitly, we need to free explicitly. 

#include "get_next_line.h"

char	*strjoin_free(char *bucket, char *spon)
{
	char	*tmp;

	tmp = ft_strjoin(bucket, spon);
	free(bucket);
	return (tmp);
}

char	*new_str(char *bucket)
{
	int	i;
	int	k;
	char	*str;

	i = 0;
	while (bucket[i] && bucket[i] != '\n')
		i++;
	if (!bucket[i])
	{
		free(bucket);
		return (NULL);
	}
	str = ft_calloc((ft_strlen(bucket) - i + 1), sizeof(char));
	i++;
	k = 0;
	while (bucket[i])
		str[k++] = bucket[i++];
	free(bucket);
	return (str);
}

char	*get_actual_line(char *bucket)
{
	int	i;
	char	*str;

	i = 0;
	if (!bucket[i])
		return (NULL);
	while (bucket[i] && bucket[i] != '\n')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (bucket[i] && bucket[i] != '\n')
	{
		str[i] = bucket[i];
		i++;
	}
	if (bucket[i] && bucket[i] == '\n')
		str[i++] = '\n';
	return (str);
}

char	*read_file(int fd, char *bucket)
{
	char	*spon;
	ssize_t	bytes_r;

	if (!bucket)
		bucket = ft_calloc(1, 1);
	spon = ft_calloc(BUFFER_SIZE + 1, sizeof(char)); 
	if (!spon)
	{
		free(bucket);
		return (NULL);
	}
	bytes_r = 1;
	while (bytes_r > 0)
	{
		bytes_r = read(fd, spon, BUFFER_SIZE);
		if (bytes_r == -1)
		{
			free(bucket);
			free(spon);
			return (NULL);
		}
		spon[bytes_r] = 0;
		bucket = strjoin_free(bucket, spon);
		if (ft_strchr(bucket, '\n'))
			break ;
	}
	free(spon);
	if (bytes_r == - 1 && bucket && *bucket)
	{
		free(bucket);
		bucket = ft_calloc(1, 1);
	}
	return (bucket);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*bucket;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);	
	bucket = read_file(fd, bucket);
	if (!bucket)
		return (NULL);
	line = get_actual_line(bucket);
	bucket = new_str(bucket);
	return (line);
}

int	main(void)
{
	int	fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("error opening file");
		return (1);
	}
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	close (fd);
	return (0);
}
