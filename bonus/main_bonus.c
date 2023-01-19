/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:04:02 by aahrach           #+#    #+#             */
/*   Updated: 2023/01/19 15:36:04 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ber(char *p)
{
	int	i;

	i = ft_strlen(p);
	i--;
	if (p[i] == 'r' && p[i - 1] == 'e' && p[i - 2] == 'b'
		&& p[i - 3] == '.' && p[i - 4] && p[i - 4] != '/')
		return (0);
	return (-1);
}

void	inisyaliz(t_gam *i)
{
	int	x;

	i->g_0 = mlx_xpm_file_to_image(i->ml, "./bonus/mag/g_0.xpm", &x, &x);
	i->g_1 = mlx_xpm_file_to_image(i->ml, "./bonus/mag/g_1.xpm", &x, &x);
	i->g_c = mlx_xpm_file_to_image(i->ml, "./bonus/mag/g_c.xpm", &x, &x);
	i->g_c2 = mlx_xpm_file_to_image(i->ml, "./bonus/mag/g_c2.xpm", &x, &x);
	i->g_d = mlx_xpm_file_to_image(i->ml, "./bonus/mag/g_d.xpm", &x, &x);
	i->g_e = mlx_xpm_file_to_image(i->ml, "./bonus/mag/g_e.xpm", &x, &x);
	i->g_ef = mlx_xpm_file_to_image(i->ml, "./bonus/mag/g_ef.xpm", &x, &x);
	i->g_es = mlx_xpm_file_to_image(i->ml, "./bonus/mag/g_es.xpm", &x, &x);
	i->g_ey = mlx_xpm_file_to_image(i->ml, "./bonus/mag/g_ey.xpm", &x, &x);
	i->g_l1 = mlx_xpm_file_to_image(i->ml, "./bonus/mag/g_l1.xpm", &x, &x);
	i->g_l2 = mlx_xpm_file_to_image(i->ml, "./bonus/mag/g_l2.xpm", &x, &x);
	i->g_n = mlx_xpm_file_to_image(i->ml, "./bonus/mag/g_n.xpm", &x, &x);
	i->g_p = mlx_xpm_file_to_image(i->ml, "./bonus/mag/g_p.xpm", &x, &x);
	if (!i->g_0 || !i->g_1 || !i->g_c || !i->g_c2 || !i->g_d || !i->g_e
		|| !i->g_ef || !i->g_es || !i->g_ey || !i->g_l1 || !i->g_l2
		|| !i->g_n || !i->g_p)
		print_error(-7, i->map, 1);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*p;
	char	**s;

	if (ac != 2 || ber(av[1]) == -1)
		print_error(0, NULL, 0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (0);
	p = get_next_line(fd);
	so_long(p);
	s = ft_split(p, '\n');
	game(s);
	return (0);
}
