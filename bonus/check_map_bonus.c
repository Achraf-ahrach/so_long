/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:04:42 by aahrach           #+#    #+#             */
/*   Updated: 2023/01/19 15:24:57 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	zero(char **p, t_map *map, int i)
{
	if (i == 0)
	{
		map->y = 0;
		while (p[map->y])
			map->y++;
		map->x = ft_strlen(p[0]);
		map->i = 0;
		map->j = 0;
		map->e = 0;
	}
	else
	{
		map->i = 1;
		map->j = 1;
		map->e = 0;
		map->p = 0;
		map->c = 0;
	}
}

int	check_e_c_p(char **p, int x, int y)
{
	t_map	map;

	map.outher = 0;
	zero(p, &map, 1);
	while (map.i < y)
	{
		map.j = 1;
		while (map.j < x)
		{
			if (p[map.i][map.j] == 'E')
				map.e++;
			else if (p[map.i][map.j] == 'P')
				map.p++;
			else if (p[map.i][map.j] == 'C')
				map.c++;
			else if (p[map.i][map.j] != '1' && p[map.i][map.j] != '0'
				&& p[map.i][map.j] != 'L')
				map.outher++;
			map.j++;
		}
		map.i++;
	}
	if (map.c > 0 && map.e == 1 && map.p == 1 && map.outher == 0)
		return (map.c);
	return (-5);
}

int	check_len_map_and_11(char **p)
{
	t_map	map;

	zero(p, &map, 0);
	while (map.i < map.y)
		if (map.x != ft_strlen(p[map.i++]))
			return (-3);
	map.y--;
	while (map.e < map.x)
	{
		if (p[0][map.e] != '1' || p[map.y][map.e] != '1')
			return (-4);
		map.e++;
	}
	while (map.j < map.y)
	{
		if (p[map.j][0] != '1' || p[map.j][map.x - 1] != '1')
			return (-4);
		map.j++;
	}
	map.c = check_e_c_p(p, map.x, map.y);
	if (map.c == -5)
		return (-5);
	return (map.c);
}

int	chek_new_lin(char *p)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(p);
	if (p[len - 1] == '\n' || p[0] == '\n')
		return (-1);
	while (p[i])
	{
		if (p[i] == '\n' && p[i + 1] == '\n')
			return (-1);
		i++;
	}
	return (0);
}

void	can_get_point_e(char **test, int x, int y, int *c_e)
{
	if (test[y][x] == 'C')
		c_e[0] += 1;
	if (test[y][x] == 'E')
	{
		c_e[1] += 1;
		return ;
	}
	if (test[y][x] == '1' || test[y][x] == 'L')
		return ;
	test[y][x] = '1';
	can_get_point_e(test, x + 1, y, c_e);
	can_get_point_e(test, x - 1, y, c_e);
	can_get_point_e(test, x, y + 1, c_e);
	can_get_point_e(test, x, y - 1, c_e);
}
