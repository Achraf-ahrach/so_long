/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:26:15 by aahrach           #+#    #+#             */
/*   Updated: 2023/01/19 15:24:42 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_nbr(int move, t_gam *gam)
{
	char	*p;

	foto_0_0(gam);
	p = ft_itoa(move);
	mlx_string_put(gam->ml, gam->wi, 4, 13, 000000, p);
	free(p);
}

void	position_of_e(t_gam *gam)
{
	int	i;
	int	j;

	i = 1;
	while (gam->map[i])
	{
		j = 1;
		while (gam->map[i][j])
		{
			if (gam->map[i][j] == 'E')
			{
				gam->y_e = i;
				gam->x_e = j;
			}
			j++;
		}
		i++;
	}
}

void	move_2(t_gam *gam, int key)
{
	int	s;

	s = 50;
	if (key == 123)
	{
		print_nbr(gam->mov++, gam);
		mlx_put_image_to_window(gam->ml, gam->wi,
			gam->g_0, (gam->x_p--) * s, gam->y_p * s);
		mlx_put_image_to_window(gam->ml, gam->wi,
			gam->g_ey, gam->x_p * s, gam->y_p * s);
	}
	else
	{
		print_nbr(gam->mov++, gam);
		mlx_put_image_to_window(gam->ml, gam->wi,
			gam->g_0, (gam->x_p++) * s, gam->y_p * s);
		mlx_put_image_to_window(gam->ml, gam->wi,
			gam->g_es, gam->x_p * s, gam->y_p * s);
	}
}

void	move_3(t_gam *gam)
{
	print_nbr(gam->mov++, gam);
	mlx_put_image_to_window(gam->ml, gam->wi, gam->g_0,
		gam->x_p * gam->s, (gam->y_p++) * gam->s);
	mlx_put_image_to_window(gam->ml, gam->wi, gam->g_p,
		gam->x_p * gam->s, gam->y_p * gam->s);
}

void	move(t_gam *gam, int key)
{
	if (gam->c == 0)
	{
		position_of_e(gam);
		mlx_put_image_to_window(gam->ml, gam->wi, gam->g_d,
			gam->x_e * gam->s, gam->y_e * gam->s);
	}
	if (key == 123)
		move_2(gam, key);
	else if (key == 124)
		move_2(gam, key);
	else if (key == 126)
	{
		print_nbr(gam->mov++, gam);
		mlx_put_image_to_window(gam->ml, gam->wi, gam->g_0,
			gam->x_p * gam->s, (gam->y_p--) * gam->s);
		mlx_put_image_to_window(gam->ml, gam->wi, gam->g_ef,
			gam->x_p * gam->s, gam->y_p * gam->s);
	}
	else if (key == 125)
		move_3(gam);
}
