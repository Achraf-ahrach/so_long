/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:04:02 by aahrach           #+#    #+#             */
/*   Updated: 2023/01/16 23:12:52 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}
//system("leaks so_long");