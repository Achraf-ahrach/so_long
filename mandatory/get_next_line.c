/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahrach <aahrach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:59:56 by aahrach           #+#    #+#             */
/*   Updated: 2023/01/16 20:11:21 by aahrach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr(int n)
{
	char	*str;

	str = "0123456789";
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n >= 0)
	{
		if (n >= 0 && n <= 9)
			write (1, &str[n], 1);
		else
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
	}
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
