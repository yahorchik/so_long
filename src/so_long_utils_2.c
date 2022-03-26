/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:23:23 by seulah            #+#    #+#             */
/*   Updated: 2022/03/08 16:23:25 by seulah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

size_t	ft_strlen(char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_isnotcharset(char c, char *set)
{
	size_t	a;

	a = 0;
	while (set[a])
	{
		if (c != set[a])
			return (1);
		a++;
	}
	return (0);
}

int	ft_int_strchr(const char *s, int c)
{
	int	a;

	a = 0;
	if (!s)
		return (-1);
	while (s[a])
	{
		if (s[a] == (char)c)
			return (a);
		a++;
	}
	if (s[a] == (char)c)
		return (a);
	return (-1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dest = (char *)malloc(sizeof(*dest) * \
		(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (dest == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		dest[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		dest[i] = *s2;
		i++;
		s2++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	new;
	char	*str;

	if (!s)
		return (NULL);
	if ((unsigned char)ft_strlen((char *)s) < start)
		return (ft_strdup(""));
	new = ft_strlen((char *)s + start);
	if (new < len)
		len = new;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
