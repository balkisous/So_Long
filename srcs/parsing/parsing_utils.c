/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:09:41 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/11/03 16:09:59 by bben-yaa         ###   ########.fr       */
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

int	message_error(t_param *p)
{
	printf("Error\n");
	free_map(p->map);
	return (-1);
}