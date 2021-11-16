/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:09:41 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/11/16 10:42:47 by bben-yaa         ###   ########.fr       */
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

void	ft_line(t_param *p)
{
	if (p->nb_of_lines <= 3)
	{
		printf("Error\n");
		free(p->map);
	}
}

int	ft_return(char **map, int i, t_param *p)
{
	
	if (ft_strlen(map[i]) == p->size_x && map[i][p->size_x - 1] == '\0')
	{
		printf("taille de map %d\n", ft_strlen(map[i]));
		printf("size_x %d\n", p->size_x);
		printf("pass here\n");
		return (1);
	}
	else if (ft_strlen(map[i]) == (p->size_x - 1) && !map[i + 1])
	{
		printf("here\n");
		return (1);
	}
	else
		return (0);
}

void	free_error(t_param *p, int i)
{
	free(p->map[i]);
	p->map[i] = NULL;
}
