/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayshok <mayshok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:42:23 by seulah            #+#    #+#             */
/*   Updated: 2022/02/16 16:27:39 by mayshok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	count_l(const char *s, char c, char **tab)
{
	int	i;
	int	str;
	int	letter;

	i = 0;
	str = 0;
	letter = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
			letter++;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			tab[str] = malloc(sizeof(char) * (letter + 1));
			if (!tab[str])
			{
				while (tab[str])
					free(tab[str--]);
			}
			str++;
			letter = 0;
		}
		i++;
	}
}

char	**count_s(const char *s, char c)
{
	int		str;
	int		i;
	char	**tab;

	i = 0;
	str = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			str++;
		i++;
	}
	tab = (char **)malloc(sizeof(char *) * (str + 1));
	if (!tab)
		return (NULL);
	return (tab);
}

void	fill_tab(char const *s, char c, char **tab)
{
	int	i;
	int	string;
	int	letter;

	i = 0;
	string = 0;
	letter = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			tab[string][letter] = s[i];
			letter++;
		}
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			tab[string][letter] = '\0';
			string++;
			letter = 0;
		}
		i++;
	}
	tab[string] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	tab = count_s(s, c);
	if (!tab)
		return (NULL);
	count_l(s, c, tab);
	fill_tab(s, c, tab);
	return (tab);
}
