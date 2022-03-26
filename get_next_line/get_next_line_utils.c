/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:04:17 by seulah            #+#    #+#             */
/*   Updated: 2021/11/09 11:04:19 by seulah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str, char x)
{
	size_t	i;

	i = 0;
	while (str[i] != x)
		i++;
	return (i);
}

void	*gnl_calloc(size_t size)
{
	char	*c;

	c = malloc(size + 1);
	if (c == NULL)
		return (NULL);
	while (size + 1 != 0)
	{
		c[size] = '\0';
		size--;
	}
	return (c);
}

char	*gnl_strdup(char *s1, char x, size_t start)
{
	char	*s2;
	size_t	buff;
	int		i;

	buff = start;
	if (s1 == NULL)
		return (NULL);
	while (s1[start] != x)
		start++;
	if (s1[start] == '\0')
		start--;
	s2 = gnl_calloc(start - buff + 1);
	if (s2 == NULL)
		return (NULL);
	i = start - buff;
	while (start + 1 != buff)
	{
		s2[i] = s1[start];
		start--;
		i--;
	}
	return (s2);
}

char	*ft_strrchr(const char *string, int symbol)
{
	int	i;

	if (string == NULL)
		return (NULL);
	i = 0;
	while (string[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (string[i] == (char)symbol)
			return ((char *)&(string[i]));
		i--;
	}
	return (NULL);
}
