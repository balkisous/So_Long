/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:12:20 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/11/03 15:58:54 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

void	draw_map(t_env *env)
{
	int	i;
	int	x;
	int	y;
	int	j;
	int	buf;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	buf = env->width;
	while (env->height--)
	{
		while (env->width--)
		{
			if (env->map[j][i++] == '1')
				draw_texture(env, x, y, &(env->wall));
			else
				draw_texture(env, x, y, &(env->grass));
			x += 64;
		}
		env->width = buf;
		add(&x, &y, &i, &j);
	}
}

int	add(int *x, int *y, int *i, int *j)
{
	*x = 0;
	*y += 64;
	*i = 0;
	(*j)++;
}

void	draw_coll_and_player(t_env *env)
{
	int	i;
	int	x;
	int	y;
	int	j;
	int	buf;

	buf = env->width;
	init_col(&x, &y, &i, &j);
	while (env->height--)
	{
		while (env->width--)
		{
			if (env->map[j][i] == 'P')
				draw_texture(env, x, y, &(env->link_down1));
			else if (env->map[j][i] == 'E')
				draw_texture(env, x, y, &(env->door));
			else if (env->map[j][i] == 'C')
				draw_texture(env, x, y, &(env->ruby));
			x += 64;
			i++;
		}
		env->width = buf;
		add(&x, &y, &i, &j);
	}
}

int	is_wall(t_env *env, int prev, char c)
{
	int	pos_xw;
	int	pos_yw;

	pos_yw = env->player.pos_y;
	pos_xw = env->player.pos_x;
	if (c == 'x')
		pos_xw = pos_xw + prev;
	else if (c == 'y')
		pos_yw = pos_yw + prev;
	if (env->map[pos_yw][pos_xw] == '1')
		return (0);
	env->p_move.pos_x = pos_xw;
	env->p_move.pos_y = pos_yw;
	return (1);
}

void	get_pos_p(t_pos *object, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == 'P')
			{
				object->pos_x = i;
				object->pos_y = j;
				break ;
			}
			i++;
		}
		i = 0;
		j++;
	}
}
