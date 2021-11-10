/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:09:41 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/11/10 11:46:58 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

void	ft_init(t_param *p, char **map)
{
	p->c = 0;
	p->e = 0;
	p->p = 0;
	p->size_x = ft_strlen(map[0]);
	p->size_y = ft_size_tab(map);
}

int	ft_name(char *str)
{
	char	*find;
	int		i;
	int		y;

	i = ft_strclen(str, '\0') - 4;
	y = 0;
	find = ".BER";
	while (str[i])
	{
		if (str[i++] == find[y])
			y++;
		else
			return (0);
	}
	return (1);
}
