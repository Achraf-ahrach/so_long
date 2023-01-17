/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:40:52 by aahrach           #+#    #+#             */
/*   Updated: 2023/01/16 22:57:43 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	buttons(int key, t_gam *gam)
{
	if (gam->map[gam->y_p][gam->x_p] == 'C')
	{
		gam->map[gam->y_p][gam->x_p] = '0';
		gam->c--;
	}
	if ((gam->map[gam->y_p][gam->x_p + 1] == 'E' && gam->c == 0)
		|| (gam->map[gam->y_p][gam->x_p - 1] == 'E' && gam->c == 0)
		|| (key == 53))
		exit(0);
	else if ((gam->map[gam->y_p - 1][gam->x_p] == 'E' && gam->c == 0)
		|| (gam->map[gam->y_p + 1][gam->x_p] == 'E' && gam->c == 0))
		exit(0);
	else if (key == 124 && gam->map[gam->y_p][gam->x_p + 1] != '1'
		&& gam->map[gam->y_p][gam->x_p + 1] != 'E')
		move(gam, 124);
	else if (key == 123 && gam->map[gam->y_p][gam->x_p - 1] != '1'
		&& gam->map[gam->y_p][gam->x_p - 1] != 'E')
		move(gam, 123);
	else if (key == 126 && gam->map[gam->y_p - 1][gam->x_p] != '1'
		&& gam->map[gam->y_p - 1][gam->x_p] != 'E')
		move(gam, 126);
	else if (key == 125 && gam->map[gam->y_p + 1][gam->x_p] != '1'
		&& gam->map[gam->y_p + 1][gam->x_p] != 'E')
		move(gam, 125);
	return (1);
}

void	moves(t_gam *gam, int i, int y, int x)
{
	void	*m;

	m = NULL;
	if (i == 0)
		mlx_hook(gam->wi, 2, 0, buttons, gam);
	if (gam->map[y][x] == '1')
		m = image(gam->ml, '1', gam->map);
	else if (gam->map[y][x] == '0')
		m = image(gam->ml, '0', gam->map);
	else if (gam->map[y][x] == 'P')
		m = image(gam->ml, 'p', gam->map);
	else if (gam->map[y][x] == 'C')
		m = image(gam->ml, 'c', gam->map);
	else if (gam->map[y][x] == 'E')
		m = image(gam->ml, 'e', gam->map);
	mlx_put_image_to_window(gam->ml, gam->wi, m, x * 50, y * 50);
}

void	*image(void	*mlx_ptr, char c, char **map)
{
	void	*imag;
	int		x;

	if (c == '0')
		imag = mlx_xpm_file_to_image(mlx_ptr, "./textures/imag_0.xpm", &x, &x);
	else if (c == '1')
		imag = mlx_xpm_file_to_image(mlx_ptr, "./textures/imag_1.xpm", &x, &x);
	else if (c == 'p')
		imag = mlx_xpm_file_to_image(mlx_ptr, "./textures/imag_p.xpm", &x, &x);
	else if (c == 'c')
		imag = mlx_xpm_file_to_image(mlx_ptr, "./textures/imag_c.xpm", &x, &x);
	else if (c == 'e')
		imag = mlx_xpm_file_to_image(mlx_ptr, "./textures/imag_e.xpm", &x, &x);
	else if (c == '^')
		imag = mlx_xpm_file_to_image(mlx_ptr, "./textures/imag_e^.xpm", &x, &x);
	else if (c == '<')
		imag = mlx_xpm_file_to_image(mlx_ptr, "./textures/imag_e<.xpm", &x, &x);
	else if (c == '>')
		imag = mlx_xpm_file_to_image(mlx_ptr, "./textures/imag_e>.xpm", &x, &x);
	else
		imag = mlx_xpm_file_to_image(mlx_ptr, "./textures/imag_d.xpm", &x, &x);
	if (!imag)
		print_error(-7, map, 1);
	return (imag);
}

int	initializ(t_gam *gam, char **map)
{
	int	i;
	int	j;

	i = -1;
	gam->c = 0;
	gam->s = 50;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				gam->c += 1;
		}
	}
	gam->y = 0;
	gam->j = 0;
	gam->mov = 1;
	gam->map = map;
	while (map[gam->y])
		gam->y++;
	gam->x = ft_strlen(map[0]);
	gam->x_p = search_p(map, 0);
	return (gam->y_p = search_p(map, 1), 50);
}

void	game(char **map)
{
	t_gam	gam;

	initializ(&gam, map);
	gam.ml = mlx_init();
	gam.wi = mlx_new_window(gam.ml, gam.x * gam.s, gam.y * gam.s, "A");
	while (gam.j < gam.y)
	{
		gam.l = 0;
		while (gam.l < gam.x)
		{
			moves(&gam, 1, gam.j, gam.l);
			gam.l++;
		}
		gam.j++;
	}
	moves(&gam, 0, 0, 0);
	mlx_loop(gam.ml);
}
//mlx_string_put())
// mlx_key_hook()