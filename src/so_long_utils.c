/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:23:39 by seulah            #+#    #+#             */
/*   Updated: 2022/03/08 16:23:40 by seulah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*so_long_build_map(t_root *mlx, t_vstock *vars)
{
	while (!mlx->stock)
	{
		mlx->stock = get_next_line(mlx->fd);
		if (!mlx->stock || !mlx->stock[0])
		{
			free (mlx->stock);
			return (mlx->map);
		}
		if (!mlx->map)
			mlx->map = ft_substr(mlx->stock, 0, ft_strlen(mlx->stock));
		else
		{
			vars->buffer = mlx->map;
			mlx->map = ft_strjoin(mlx->map, mlx->stock);
			free (vars->buffer);
		}
		ft_free(&mlx->stock);
	}
	return (mlx->map);
}

int	so_long_check_tile(t_root *mlx, char tile)
{
	if (tile == 'E')
	{
		if (ft_int_strchr(mlx->map, 'C') == -1)
		{
			so_long_close_window(&*mlx);
			return (0);
		}
		else
			return (so_long_error_2(17));
	}
	else if (tile == '1')
		return (so_long_error_2(18));
	return (1);
}

char	*ft_strdup(const char *source)
{
	int		i;
	int		l;
	char	*str;

	l = 0;
	while (source[l] != '\0')
		l++;
	str = (char *)malloc(sizeof(*str) * (l + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < l)
	{
		str[i] = source[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_free(char **str)
{
	free (*str);
	*str = NULL;
}

size_t	ft_strlcpy(char *dest, const char *source, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen((char *)source));
	i = 0;
	while (i < size - 1 && source[i])
	{
		((char *)dest)[i] = ((char *)source)[i];
		i++;
	}
	((char *)dest)[i] = '\0';
	return (ft_strlen(((char *)source)));
}
