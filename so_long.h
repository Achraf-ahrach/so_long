/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:10:04 by aahrach           #+#    #+#             */
/*   Updated: 2023/01/16 23:12:20 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct s_map{
	int	x;
	int	y;
	int	outher;
	int	i;
	int	j;
	int	e;
	int	c;
	int	p;
}	t_map;

typedef struct s_main{
	char	**s;
	char	**test;
	int		c;
	int		x_p;
	int		y_p;
}	t_main;

typedef struct s_gam{
	int		x;
	int		y;
	int		mov;
	int		s;
	int		x_p;
	int		y_p;
	int		x_e;
	int		y_e;
	int		c;
	int		j;
	int		l;
	void	*ml;
	void	*wi;
	void	*_1;
	void	*_2;
	char	**map;
}	t_gam;

char	*get_next_line(int fd);
void	ft_free(char **p);
int		search_p(char **test, int i);
char	**ft_split(char *s, char c);
int		chek_new_lin(char *p);
void	game(char **map);
void	ft_putnbr(int n);
void	print_error(int i, char **map, int x);
void	so_long(char *p);
void	*image(void	*mlx_ptr, char c, char **map);
int		check_len_map_and_11(char **p);
void	move(t_gam *game, int key);
void	can_get_point_e(char **test, int x, int y, int *c_e);
int		ft_strlen(char *s);

#endif