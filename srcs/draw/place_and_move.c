/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_and_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:51:44 by user42@stud       #+#    #+#             */
/*   Updated: 2021/11/03 16:07:47 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

void	define_place(t_env *env)
{
	env->b_player.pos_x = env->player.pos_x;
	env->b_player.pos_y = env->player.pos_y;
	env->player.pos_x = env->p_move.pos_x;
	env->player.pos_y = env->p_move.pos_y;
}

void	print_exit(t_env *env)
{
	if (env->map[env->b_player.pos_y][env->b_player.pos_x] == 'E')
		draw_texture(env, env->b_player.pos_x * env->bppe, \
		env->b_player.pos_y * env->bppe, &(env->door));
}

void	move(t_env *env)
{
	if (env->key == KEY_W)
		draw_texture(env, env->player.pos_x * env->bppe, \
		env->player.pos_y * env->bppe, &(env->link_up1));
	else if (env->key == KEY_A)
		draw_texture(env, env->player.pos_x * env->bppe, \
		env->player.pos_y * env->bppe, &(env->link_left1));
	else if (env->key == KEY_S)
		draw_texture(env, env->player.pos_x * env->bppe, \
		env->player.pos_y * env->bppe, &(env->link_down1));
	else if (env->key == KEY_D)
		draw_texture(env, env->player.pos_x * env->bppe, \
		env->player.pos_y * env->bppe, &(env->link_right1));
}

void	move2(t_env *env)
{
	if (env->key == KEY_W)
		draw_texture(env, env->player.pos_x * env->bppe, \
		env->player.pos_y * env->bppe, &(env->link_up2));
	else if (env->key == KEY_A)
		draw_texture(env, env->player.pos_x * env->bppe, \
		env->player.pos_y * env->bppe, &(env->link_left2));
	else if (env->key == KEY_S)
		draw_texture(env, env->player.pos_x * env->bppe, \
		env->player.pos_y * env->bppe, &(env->link_down2));
	else if (env->key == KEY_D)
		draw_texture(env, env->player.pos_x * env->bppe, \
		env->player.pos_y * env->bppe, &(env->link_right2));
}

void	move_p(t_env *env)
{
	if (env->step % 2 == 0)
		move(env);
	else
		move2(env);
}
