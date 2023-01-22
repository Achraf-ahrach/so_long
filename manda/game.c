/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:40:52 by aahrach           #+#    #+#             */
/*   Updated: 2023/01/19 19:13:16 by aahrach          ###   ########.fr       */
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
	if (key == 53)
	{
		exit(0);
	}
	if (key == 123 || key == 124 || key == 125 || key == 126)
		check_dor(gam, key);
	if (key == 124 && gam->map[gam->y_p][gam->x_p + 1] != '1'
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
	if (i == 0)
		mlx_hook(gam->wi, 2, 0, buttons, gam);
	if (gam->map[y][x] == '1')
		mlx_put_image_to_window(gam->ml, gam->wi, gam->g_1, x * 50, y * 50);
	else if (gam->map[y][x] == '0')
		mlx_put_image_to_window(gam->ml, gam->wi, gam->g_0, x * 50, y * 50);
	else if (gam->map[y][x] == 'P')
		mlx_put_image_to_window(gam->ml, gam->wi, gam->g_p, x * 50, y * 50);
	else if (gam->map[y][x] == 'C')
		mlx_put_image_to_window(gam->ml, gam->wi, gam->g_c, x * 50, y * 50);
	else if (gam->map[y][x] == 'E')
		mlx_put_image_to_window(gam->ml, gam->wi, gam->g_e, x * 50, y * 50);
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

void	inisyaliz(t_gam *i)
{
	int	x;

	i->g_0 = mlx_xpm_file_to_image(i->ml, "./manda/mag/g_0.xpm", &x, &x);
	i->g_1 = mlx_xpm_file_to_image(i->ml, "./manda/mag/g_1.xpm", &x, &x);
	i->g_c = mlx_xpm_file_to_image(i->ml, "./manda/mag/g_c.xpm", &x, &x);
	i->g_d = mlx_xpm_file_to_image(i->ml, "./manda/mag/g_d.xpm", &x, &x);
	i->g_e = mlx_xpm_file_to_image(i->ml, "./manda/mag/g_e.xpm", &x, &x);
	i->g_ef = mlx_xpm_file_to_image(i->ml, "./manda/mag/g_ef.xpm", &x, &x);
	i->g_es = mlx_xpm_file_to_image(i->ml, "./manda/mag/g_es.xpm", &x, &x);
	i->g_ey = mlx_xpm_file_to_image(i->ml, "./manda/mag/g_ey.xpm", &x, &x);
	i->g_p = mlx_xpm_file_to_image(i->ml, "./manda/mag/g_p.xpm", &x, &x);
	if (!i->g_0 || !i->g_1 || !i->g_c || !i->g_e || !i->g_d
		|| !i->g_ef || !i->g_es || !i->g_ey || !i->g_p)
		print_error(-7, i->map, 1);
}

void	game(char **map)
{
	t_gam	gam;

	initializ(&gam, map);
	gam.ml = mlx_init();
	gam.wi = mlx_new_window(gam.ml, gam.x * gam.s, gam.y * gam.s, "A");
	inisyaliz(&gam);
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
	mlx_hook(gam.wi, 17, 0, func, &gam);
	mlx_loop(gam.ml);
}
