/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:05:24 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/11/15 11:21:30 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

int	ft_pars_name(char *str)
{
	int		i;
	int		y;
	char	*find;

	i = ft_strclen(str, '\0') - 4;
	y = 0;
	if (i < 0)
		return (0);
	find = ".ber";
	if (str[i + 1] == 'b')
	{
		while (str[i])
		{
			if (str[i++] == find[y])
				y++;
			else
				return (0);
		}
		return (1);
	}
	return (ft_name(str));
}

int	ft_parse_arg(int argc, char **argv)
{
	if (argc != 2)
		printf("Error\n");
	else if (!ft_pars_name(argv[1]))
		printf("Error\n");
	else if (ft_pars_name(argv[1]))
		return (1);
	return (0);
}

int	ft_size_tab(char **map)
{
	int	j;

	j = 1;
	while (map[j])
	{
		if (map[j][0] == '\n')
			return (j);
		j++;
	}
	return (j);
}

int	is_one(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

int	check_one(char **map, t_param *p)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (i == 0 && !is_one(map[0], '1'))
			return (0);
		if (map[i][0] == '\n')
			break ;
		if (map[i][0] != '1' || map[i][p->size_x - 2] != '1')
			return (0);
		if (i == (p->size_y - 1) && !is_one(map[i], '1'))
			return (0);
		i++;
	}
	return (1);
}
