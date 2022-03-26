/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:22:30 by seulah            #+#    #+#             */
/*   Updated: 2022/03/08 16:22:33 by seulah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	so_long_check_wall_error(char *mapstock)
{
	char	**spmap;
	size_t	a;
	size_t	slen;

	spmap = ft_split(mapstock, '\n');
	slen = ft_strlen(spmap[0]);
	a = 0;
	if (ft_isnotcharset('1', spmap[0]))
		return (so_long_solve_spmap(spmap) * so_long_error(3));
	while (spmap[a])
	{
		if (ft_strlen(spmap[a]) != slen)
			return (so_long_solve_spmap(spmap) * so_long_error_2(14));
		if (spmap[a][slen - 1] != '1' || spmap[a][0] != '1')
			return (so_long_solve_spmap(spmap) * so_long_error(4));
		a++;
	}
	if (ft_isnotcharset('1', spmap[a - 1]))
		return (so_long_solve_spmap(spmap) * so_long_error(6));
	so_long_solve_spmap(spmap);
	return (1);
}

static int	so_long_check_map_error(t_root *mlx, t_vstock *vars)
{
	int	a;

	a = 0;
	vars->p_c = 0;
	vars->e_c = 0;
	vars->c_c = 0;
	while (mlx->map[a++])
	{
		if (ft_int_strchr(MAPSET, mlx->map[a]) == -1)
			return (so_long_error_2(15));
		if (mlx->map[a] == 'P')
			vars->p_c++;
		if (mlx->map[a] == 'E')
			vars->e_c++;
		if (mlx->map[a] == 'C')
			vars->c_c++;
		if (mlx->map[a] == '\n' || mlx->map[a] == '\0')
			mlx->ynb++;
	}
	if (!so_long_check_wall_error(mlx->map) || vars->p_c != 1
		|| vars->e_c < 1 || vars->c_c < 1)
		return (so_long_errhub(vars->p_c, vars->e_c, vars->c_c));
	mlx->xnb = ft_int_strchr(mlx->map, '\n');
	return (1);
}

static char	*so_long_init_map(char *av, t_root *mlx)
{
	t_vstock	vars;

	mlx->map = NULL;
	mlx->stock = NULL;
	vars.buffer = NULL;
	mlx->fd = open(av, O_RDONLY);
	if (mlx->fd < 0)
	{
		so_long_error_2(20);
		return (NULL);
	}
	mlx->map = so_long_build_map(&*mlx, &vars);
	close (mlx->fd);
	if (!so_long_check_map_error(&*mlx, &vars))
	{
		free (mlx->map);
		return (NULL);
	}
	return (mlx->map);
}

static void	so_long_init_img(t_root *mlx)
{
	size_t	a;

	a = 0;
	mlx->ipath[0] = "img/collected.xpm";
	mlx->ipath[1] = "img/main_hero.xpm";
	mlx->ipath[2] = "img/exit.xpm";
	mlx->ipath[3] = "img/floor.xpm";
	mlx->ipath[4] = "img/wall.xpm";
	while (a <= 4)
	{
		mlx->iptr[a] = mlx_xpm_file_to_image(mlx->ptr, mlx->ipath[a],
				&mlx->iwidth[a], &mlx->iheight[a]);
		a++;
	}
}

int	main(int ac, char *av[])
{
	t_root	mlx;

	if (ac != 2)
		return (so_long_error(1));
	mlx.map = so_long_init_map(av[1], &mlx);
	if (!mlx.map)
		return (so_long_error(2));
	mlx.ptr = mlx_init();
	so_long_init_img(&mlx);
	mlx.win = mlx_new_window(mlx.ptr, mlx.xnb * 64, mlx.ynb * 64, "so_long");
	so_long_game_loop(&mlx);
	mlx.iloop = mlx_loop(mlx.ptr);
	return (0);
}
