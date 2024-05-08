/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andos-sa <andos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:21:18 by andos-sa          #+#    #+#             */
/*   Updated: 2024/05/06 17:53:12 by andos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *line, char *buffer)
{
	char	*new_line;
	int		len;
	int		i;
	int		k;

	len = ft_strlen(line) + ft_strlen(buffer);
	new_line = (char *)malloc(len + 1);
	if (!new_line)
	{
		if (line != NULL)
			free(line);
		return (NULL);
	}
	i = 0;
	k = 0;
	while (line != NULL && line[k] != '\0')
		new_line[i++] = line[k++];
	k = 0;
	while (buffer[k] != '\0')
		new_line[i++] = buffer[k++];
	new_line[i] = '\0';
	free(line);
	return (ft_cut_line(new_line));
}

char	*ft_cut_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
		line[++i] = '\0';
	return (line);
}

int	ft_clear_buffer(char *buffer)
{
	int	i;
	int	len_buffer;
	int	nl;
	int	check;

	len_buffer = ft_strlen(buffer);
	nl = 0;
	while (buffer[nl] != '\n' && buffer[nl] != '\0')
		nl++;
	check = 0;
	if (buffer[nl] == '\n')
		check = 1;
	i = 0;
	while (i < len_buffer)
	{
		if (nl + i < len_buffer)
		{
			buffer[i] = buffer[nl + i + 1];
			buffer[nl + i + 1] = '\0';
		}
		else
			buffer[i] = '\0';
		i++;
	}
	return (check);
}

int	ft_strlen(char *string)
{
	int	i;

	i = 0;
	if (string == NULL)
		return (i);
	while (string[i] != '\0')
		i++;
	return (i);
}
