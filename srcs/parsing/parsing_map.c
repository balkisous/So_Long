/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:24:52 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/11/04 11:56:12 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

int	check_size_tab(char **map, t_param *p)
{
	int	i;

	i = 0;
	p->size_x = ft_strlen(map[0]);
	while (map[i])
	{
		if (map[i][0] == '\n')
		{
			while (map[i])
			{
				if (map[i][0] != '\n')
					return (0);
				i++;
			}
			break ;
		}
		else if (ft_strlen(map[i]) != p->size_x)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find(char *str, char c)
{
	int	i;
	int	curs;

	i = 0;
	curs = 0;
	while (str[i])
	{
		if (str[i] == c)
			curs++;
		i++;
	}
	if (curs == 1)
		return (1);
	return (0);
}

int	check_char(char **map)
{
	int		x;
	int		y;
	char	*str;

	str = "10CPE\n";
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x] != '\0')
		{
			if (!ft_find(str, map[y][x]))
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

int	ft_count(char **map, t_param *p)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				p->p++;
			else if (map[y][x] == 'C')
				p->c++;
			else if (map[y][x] == 'E')
				p->e++;
			x++;
		}
		x = 0;
		y++;
	}
	if (p->p != 1 || !p->e || !p->c)
		return (0);
	return (1);
}

int	ft_parsing(char **map, t_param *p)
{
	ft_init(p, map);
	if (check_size_tab(map, p))
	{
		if (!check_one(map, p))
			return (0);		
		if (!check_char(map))
			return (0);
		if (!ft_count(map, p))
			return (0);
		return (1);
	}
	return (0);
}
