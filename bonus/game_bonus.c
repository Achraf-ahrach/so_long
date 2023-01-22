/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:40:52 by aahrach           #+#    #+#             */
/*   Updated: 2023/01/21 10:44:27 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	n9es_f_c(int key, t_gam *gam)
{
	if ((key == 123) && gam->map[gam->y_p][gam->x_p - 1] == 'C')
	{
		gam->c--;
		gam->map[gam->y_p][gam->x_p - 1] = '0';
	}
	if ((key == 124) && gam->map[gam->y_p][gam->x_p + 1] == 'C')
	{
		gam->c--;
		gam->map[gam->y_p][gam->x_p + 1] = '0';
	}
	if ((key == 125) && gam->map[gam->y_p + 1][gam->x_p] == 'C')
	{
		gam->c--;
		gam->map[gam->y_p + 1][gam->x_p] = '0';
	}
	if ((key == 126) && gam->map[gam->y_p - 1][gam->x_p] == 'C')
	{
		gam->c--;
		gam->map[gam->y_p - 1][gam->x_p] = '0';
	}
}

int	buttons(int key, t_gam *gam)
{
	if (gam->map[gam->y_p][gam->x_p] == 'C')
	{
		gam->map[gam->y_p][gam->x_p] = '0';
		gam->c--;
	}
	if (key == 53)
		exit(0);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		check_dor(key, gam);
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

void	moves(t_gam *i, int y, int x, int l)
{
	if (l == 1)
		mlx_hook(i->wi, 2, 0, buttons, i);
	if (i->map[y][x] == '1')
		mlx_put_image_to_window(i->ml, i->wi, i->g_1, x * 50, y * 50);
	else if (i->map[y][x] == '0')
		mlx_put_image_to_window(i->ml, i->wi, i->g_0, x * 50, y * 50);
	else if (i->map[y][x] == 'P')
		mlx_put_image_to_window(i->ml, i->wi, i->g_p, x * 50, y * 50);
	else if (i->map[y][x] == 'C')
		mlx_put_image_to_window(i->ml, i->wi, i->g_c, x * 50, y * 50);
	else if (i->map[y][x] == 'E')
		mlx_put_image_to_window(i->ml, i->wi, i->g_e, x * 50, y * 50);
	else if (i->map[y][x] == 'L')
		mlx_put_image_to_window(i->ml, i->wi, i->g_l1, x * 50, y * 50);
}

void	game(char **map)
{
	t_gam	gam;
	int		i;

	i = 0;
	initializ(&gam, map);
	gam.ml = mlx_init();
	gam.wi = mlx_new_window(gam.ml, gam.x * gam.s, gam.y * gam.s, "ACHRAF");
	inisyaliz(&gam);
	while (gam.j < gam.y)
	{
		gam.l = 0;
		while (gam.l < gam.x)
		{
			moves(&gam, gam.j, gam.l, 1);
			gam.l++;
		}
		gam.j++;
	}
	moves(&gam, 0, 0, 0);
	foto_0_0(&gam);
	mlx_loop_hook(gam.ml, lmakla_and_e, &gam);
	mlx_hook(gam.wi, 17, 0, func, &gam);
	mlx_loop(gam.ml);
}
