/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andos-sa <andos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:02:12 by andos-sa          #+#    #+#             */
/*   Updated: 2024/05/06 17:35:59 by andos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes;

	line = NULL;
	while (1)
	{
		if (buffer[0] == '\0')
		{
			bytes = read(fd, buffer, BUFFER_SIZE);
			if (bytes == 0)
				return (line);
			else if (bytes == -1)
			{
				if (line != NULL)
					free(line);
				return (NULL);
			}
		}
		line = ft_strjoin(line, buffer);
		if (ft_clear_buffer(buffer) == 1)
			break ;
	}
	return (line);
}

// int	main(void)
// {
// 	int	fd;
// 	char *line;

// 	fd = 42;
// 	if (fd == -1)
// 	{
// 		printf("error opening file");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		if (line[0] != '\0')
// 		{
// 			printf("%s",line);
// 			free(line);
// 		}
// 	}
// 	printf("%s\n", line);
// 	close(fd);
// 	return (0);
// }
