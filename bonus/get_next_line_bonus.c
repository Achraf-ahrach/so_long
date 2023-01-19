/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:59:56 by aahrach           #+#    #+#             */
/*   Updated: 2023/01/19 15:24:48 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*p;
	int		nb;

	i = 0;
	j = 0;
	nb = n;
	while (n >= 1)
	{
		n = n / 10;
		i++;
	}
	p = malloc(i + 1);
	if (!p)
		return (NULL);
	p[i--] = '\0';
	while (i >= j)
	{
		p[i--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (p);
}

void	foto_0_0(t_gam *gam)
{
	mlx_put_image_to_window(gam->ml, gam->wi, gam->g_n, 0, 0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (p == 0)
		return (NULL);
	while (*s1)
		p[i++] = *s1++;
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	return (p);
}

char	*get_next_line(int fd)
{
	char	buf[7];
	char	*str;
	char	*p;
	int		i;

	str = "";
	i = read(fd, buf, 6);
	while (i > 0)
	{
		buf[i] = 0;
		p = str;
		str = ft_strjoin(str, buf);
		if (!str)
			return (free(p), NULL);
		if (*p)
			free(p);
		i = read(fd, buf, 6);
	}
	return (str);
}
