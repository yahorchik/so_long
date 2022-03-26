/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:23:09 by seulah            #+#    #+#             */
/*   Updated: 2022/03/08 16:23:11 by seulah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	so_long_close_window(t_root *mlx)
{
	size_t	a;

	a = 0;
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_window(mlx->ptr, mlx->win);
	while (a <= 4)
	{
		mlx_destroy_image(mlx->ptr, mlx->iptr[a]);
		mlx->iptr[a] = NULL;
		a++;
	}
	mlx->ptr = NULL;
	mlx->win = NULL;
	a = so_long_error_2(19);
	exit(mlx->iloop);
	return (1);
}

static int	so_long_checkdest(int key, t_root *mlx)
{
	int	p;

	p = ft_int_strchr(mlx->map, 'P');
	if (key == K_W || key == K_UP)
	{
		if (!so_long_check_tile(&*mlx, mlx->map[p - mlx->xnb - 1]))
			return (so_long_error(9));
	}
	else if (key == K_A || key == K_LEFT)
	{
		if (!so_long_check_tile(&*mlx, mlx->map[p - 1]))
			return (so_long_error(10));
	}
	else if (key == K_S || key == K_DOWN)
	{
		if (!so_long_check_tile(&*mlx, mlx->map[p + mlx->xnb + 1]))
			return (so_long_error(11));
	}
	else if (key == K_D || key == K_RIGHT)
	{
		if (!so_long_check_tile(&*mlx, mlx->map[p + 1]))
			return (so_long_error(12));
	}
	return (p);
}

static int	so_long_display_map(t_root mlx)
{
	int	a;
	int	i;

	a = 0;
	while (mlx.map[a])
	{
		i = ft_int_strchr(MAPSET, mlx.map[a]);
		if (i == 1)
		{
			mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.iptr[3],
				mlx.x * 64, mlx.y * 64);
		}
		if (i >= 0 && i < 5)
			mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.iptr[i],
				mlx.x++ *64, mlx.y * 64);
		else if (i == 5)
		{
			mlx.xnb = mlx.x;
			mlx.x = 0;
			mlx.y++;
		}
		a++;
	}
	return (0);
}

static int	so_long_hub_keypress(int key, t_root *mlx)
{
	static int	movecount;
	int			p;

	p = so_long_checkdest(key, &*mlx);
	if (p == 0)
		return (0);
	if (key == K_W || key == K_UP || key == K_A || key == K_LEFT
		|| key == K_S || key == K_DOWN || key == K_D || key == K_RIGHT)
	{
		mlx->map[p] = '0';
		if (key == K_W || key == K_UP)
			mlx->map[p - mlx->xnb - 1] = 'P';
		else if (key == K_A || key == K_LEFT)
			mlx->map[p - 1] = 'P';
		else if (key == K_S || key == K_DOWN)
			mlx->map[p + mlx->xnb + 1] = 'P';
		else if (key == K_D || key == K_RIGHT)
			mlx->map[p + 1] = 'P';
		printf("movecount : %d\n", ++movecount);
		mlx_clear_window(mlx->ptr, mlx->win);
		so_long_display_map(*mlx);
	}
	if (key == K_ESC)
		so_long_close_window(&*mlx);
	return (1);
}

void	so_long_game_loop(t_root *mlx)
{
	so_long_display_map(*mlx);
	mlx_hook(mlx->win, 2, 0, so_long_hub_keypress, &*mlx);
	mlx_hook(mlx->win, 17, 0, so_long_close_window, &*mlx);
}
