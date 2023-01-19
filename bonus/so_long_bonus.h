/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:10:04 by aahrach           #+#    #+#             */
/*   Updated: 2023/01/19 15:24:14 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	void	*g_0;
	void	*g_1;
	void	*g_c;
	void	*g_c2;
	void	*g_d;
	void	*g_e;
	void	*g_ef;
	void	*g_ey;
	void	*g_es;
	void	*g_l1;
	void	*g_l2;
	void	*g_n;
	void	*g_p;
	char	**map;
}	t_gam;

typedef struct s_i{
	void	*imag;
	int		x;
}	t_i;

char	*get_next_line(int fd);
void	ft_free(char **p);
int		search_p(char **test, int i);
char	**ft_split(char *s, char c);
int		chek_new_lin(char *p);
void	game(char **map);
void	print_error(int i, char **map, int x);
void	so_long(char *p);
int		check_len_map_and_11(char **p);
void	move(t_gam *game, int key);
void	can_get_point_e(char **test, int x, int y, int *c_e);
int		ft_strlen(char *s);
char	*ft_itoa(int n);
int		funct_ptr(t_gam *gam);
void	foto_0_0(t_gam *gam);
void	check_dor(int key, t_gam *gam);
int		lmakla_and_e(t_gam *gam);
int		initializ(t_gam *gam, char **map);
int		func(t_gam *gam);
void	n9es_f_c(int key, t_gam *gam);
void	inisyaliz(t_gam *i);

#endif