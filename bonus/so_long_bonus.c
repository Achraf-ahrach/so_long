/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:09:54 by aahrach           #+#    #+#             */
/*   Updated: 2023/01/19 15:24:38 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_error(int i, char **map, int x)
{
	if (i == 0)
		write (1, "Error\nargemon is not 2, or *.ber\n", 34);
	else if (i == -1)
		write (1, "Error\nkayn new_lin\n", 20);
	else if (i == -2)
		write (1, "Error\ncheck_len_map_and_11\n", 28);
	else if (i == -3)
		write (1, "Error\nlen dyal stor\n", 21);
	else if (i == -4)
		write (1, "Error\nlkadr madayr b 11\n", 25);
	else if (i == -5)
		write (1, "Error\ncheck_e_c_p\n", 19);
	else if (i == -6)
		write (1, "Error\nnot can P get to E or to all C\n", 38);
	else if (i == -7)
		write (1, "Error\nimage !\n", 15);
	else if (i == 1)
		write (1, "rbahti assadik !\n", 18);
	else if (i == 2)
		write (1, "khsarti assadik !\n", 19);
	if (x == 1)
		ft_free(map);
	exit(1);
}

int	search_p(char **test, int i)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (test[y])
	{
		x = 1;
		while (test[y][x])
		{
			if (test[y][x] == 'P')
			{
				if (i == 0)
					return (x);
				return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_free(char **p)
{
	int	i;

	i = 0;
	if (!p)
		return ;
	while (p[i])
		free(p[i++]);
	free(p);
}

void	initialize(t_main *main, int *c_e)
{
	c_e[0] = 0;
	c_e[1] = 0;
	main->x_p = search_p(main->test, 0);
	main->y_p = search_p(main->test, 1);
}

void	so_long(char *p)
{
	t_main	main;
	int		c_e[2];

	main.test = ft_split(p, '\n');
	if (chek_new_lin(p) == -1)
		print_error(-1, main.test, 1);
	main.c = check_len_map_and_11(main.test);
	if (main.c < 0)
		print_error(main.c, main.test, 1);
	initialize(&main, c_e);
	can_get_point_e(main.test, main.x_p, main.y_p, c_e);
	if (c_e[1] == 0 || c_e[0] != main.c)
		print_error(-6, main.test, 1);
	ft_free(main.test);
}
