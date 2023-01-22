/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:04:02 by aahrach           #+#    #+#             */
/*   Updated: 2023/01/22 09:50:47 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	func(t_gam *gam)
{
	mlx_destroy_window(gam->ml, gam->wi);
	exit(1);
}

void	check_dor(t_gam *gam, int key)
{
	if ((key == 126) && gam->map[gam->y_p - 1][gam->x_p] == 'E' && !gam->c)
		print_error(1, NULL, 0);
	if ((key == 125) && gam->map[gam->y_p + 1][gam->x_p] == 'E' && !gam->c)
		print_error(1, NULL, 0);
	if ((key == 124) && gam->map[gam->y_p][gam->x_p + 1] == 'E' && !gam->c)
		print_error(1, NULL, 0);
	if ((key == 123) && gam->map[gam->y_p][gam->x_p - 1] == 'E' && !gam->c)
		print_error(1, NULL, 0);
}

int	ber(char *p)
{
	int	i;

	i = ft_strlen(p);
	if (i < 5)
		return (-1);
	i--;
	if (p[i] == 'r' && p[i - 1] == 'e' && p[i - 2] == 'b'
		&& p[i - 3] == '.' && p[i - 4] && p[i - 4] != '/')
		return (0);
	return (-1);
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
		print_error(-8, NULL, 0);
	p = get_next_line(fd);
	so_long(p);
	s = ft_split(p, '\n');
	game(s);
	return (0);
}
