/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:26:15 by seulah            #+#    #+#             */
/*   Updated: 2022/03/08 16:26:17 by seulah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "../mlx/mlx.h"
# include <stdio.h>
# include "so_long_keys.h"
# include "../get_next_line/get_next_line.h"

# define MAPSET "CPE01\n"

typedef struct s_root
{
	void	*ptr;
	void	*win;
	int		iloop;
	void	*iptr[5];
	char	*ipath[5];
	int		iwidth[5];
	int		iheight[5];
	char	*map;
	int		xnb;
	int		ynb;
	int		x;
	int		y;
	char	*stock;
	int		fd;
}	t_root;

typedef struct s_vstock
{
	char	*buffer;
	int		p_c;
	int		e_c;
	int		c_c;
}	t_vstock;

char	*so_long_build_map(t_root *mlx, t_vstock *vars);
int		so_long_check_tile(t_root *mlx, char tile);

void	so_long_game_loop(t_root *mlx);
int		so_long_close_window(t_root *mlx);

int		so_long_solve_spmap(char **spmap);
int		so_long_solve_img(t_root *mlx);
int		so_long_errhub(int pcount, int ecount, int ccount);
int		so_long_error(int nb);
int		so_long_error_2(int nb);

char	**ft_split(char const *s, char c);
int		ft_int_strchr(const char *s, int c);
int		ft_isnotcharset(char c, char *set);
size_t	ft_strlen(char *c);
void	ft_free(char **str);
char	*ft_strdup(const char *source);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *source, size_t size);

#endif
