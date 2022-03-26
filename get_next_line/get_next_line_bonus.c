/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:03:33 by seulah            #+#    #+#             */
/*   Updated: 2021/11/09 11:03:36 by seulah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*gnl_clear(char **clear)
{
	free(*clear);
	*clear = NULL;
	return (NULL);
}

static char	*gnl_strjoin(char *start, char *end)
{
	size_t	i;
	size_t	j;
	char	*buff;

	buff = malloc(gnl_strlen(start, '\0') + gnl_strlen(end, '\0') + 1);
	if (buff == NULL)
		return (NULL);
	i = 0;
	while (start[i] != '\0')
	{
		buff[i] = start[i];
		i++;
	}
	j = 0;
	while (end[j] != '\0')
	{
		buff[i] = end[j];
		i++;
		j++;
	}
	buff[i] = '\0';
	free(start);
	return (buff);
}

static void	gnl_read(char **result, int fd)
{
	char	*buff;
	int		readed_byte;

	buff = gnl_calloc(BUFFER_SIZE + 1);
	readed_byte = read(fd, buff, BUFFER_SIZE);
	while (readed_byte > 0)
	{
		buff[readed_byte] = '\0';
		if (*result == NULL)
			*result = gnl_strdup(buff, '\0', 0);
		else
			*result = gnl_strjoin(*result, buff);
		if (ft_strrchr(*result, '\n') != NULL)
			break ;
		readed_byte = read(fd, buff, BUFFER_SIZE);
	}
	if (readed_byte < 0)
		gnl_clear(result);
	gnl_clear(&buff);
}

char	*get_next_line(int fd)
{
	static char	*result[10240];
	char		*buff;
	char		*res;

	if (fd < 0)
		return (NULL);
	gnl_read(&result[fd], fd);
	if (result[fd] == NULL || result[fd][0] == '\0')
		return (NULL);
	else if (ft_strrchr(result[fd], '\n') != NULL)
	{
		res = gnl_strdup(result[fd], '\n', 0);
		buff = gnl_strdup(result[fd], '\0', gnl_strlen(result[fd], '\n') + 1);
		free(result[fd]);
		result[fd] = buff;
		if (result[fd][0] == '\0')
			gnl_clear(&result[fd]);
	}
	else
	{
		res = gnl_strdup(result[fd], '\0', 0);
		gnl_clear(&result[fd]);
	}
	return (res);
}
