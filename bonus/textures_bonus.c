/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:54:37 by aahrach           #+#    #+#             */
/*   Updated: 2023/01/21 18:46:41 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	look_c(t_gam *gam, void	*imag, int i)
{
	int		y;
	int		x;

	y = 0;
	while (gam->map[y])
	{
		x = 0;
		while (gam->map[y][x])
		{
			if (gam->map[y][x] == 'C' && i == 1)
				mlx_put_image_to_window(gam->ml, gam->wi, imag, x * 50, y * 50);
			if (gam->map[y][x] == 'L' && i == 2)
				mlx_put_image_to_window(gam->ml, gam->wi, imag, x * 50, y * 50);
			x++;
		}
		y++;
	}
	return (0);
}

int	func(t_gam *gam)
{
	mlx_destroy_window(gam->ml, gam->wi);
	exit(1);
}

int	lmakla_and_e(t_gam *i)
{
	static int	n;

	n++;
	if (n == 15000)
		n = 0;
	if (n == 0 || n == 9000)
		look_c(i, i->g_0, 2);
	if (n == 10)
		look_c(i, i->g_c, 1);
	if (n == 1)
		look_c(i, i->g_l2, 2);
	if (n == 7500)
		look_c(i, i->g_c2, 1);
	if (n == 9001)
		look_c(i, i->g_l1, 2);
	return (0);
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

void	check_dor(int key, t_gam *gam)
{
	if (key == 123 || key == 124 || key == 125 || key == 126)
		n9es_f_c(key, gam);
	if ((key == 126) && !gam->c && gam->map[gam->y_p - 1][gam->x_p] == 'E')
		print_error(1, NULL, 0);
	if ((key == 125) && gam->map[gam->y_p + 1][gam->x_p] == 'E' && !gam->c)
		print_error(1, NULL, 0);
	if ((key == 124) && gam->map[gam->y_p][gam->x_p + 1] == 'E' && !gam->c)
		print_error(1, NULL, 0);
	if ((key == 123) && gam->map[gam->y_p][gam->x_p - 1] == 'E' && !gam->c)
		print_error(1, NULL, 0);
	if (((key == 126) && gam->map[gam->y_p - 1][gam->x_p] == 'L')
		|| ((key == 125) && gam->map[gam->y_p + 1][gam->x_p] == 'L'))
		print_error(2, NULL, 0);
	if (((key == 124) && gam->map[gam->y_p][gam->x_p + 1] == 'L')
	|| ((key == 123) && gam->map[gam->y_p][gam->x_p - 1] == 'L'))
		print_error(2, NULL, 0);
}
