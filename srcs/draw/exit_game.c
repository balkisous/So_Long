/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:36:02 by user42@stud       #+#    #+#             */
/*   Updated: 2021/11/03 16:00:44 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

void	destroy_image(t_env *env, t_img *img)
{
	if (img)
		mlx_destroy_image(env->prms.mlx, img->img);
}

void	destroy_all_images(t_env *env)
{
	destroy_image(env, &(env->wall));
	destroy_image(env, &(env->grass));
	destroy_image(env, &(env->ruby));
	destroy_image(env, &(env->door));
	destroy_image(env, &(env->link_down1));
	destroy_image(env, &(env->link_down2));
	destroy_image(env, &(env->link_right1));
	destroy_image(env, &(env->link_right2));
	destroy_image(env, &(env->link_left1));
	destroy_image(env, &(env->link_left2));
	destroy_image(env, &(env->link_up1));
	destroy_image(env, &(env->link_up2));
}

int	quit_game(t_env *env)
{
	destroy_all_images(env);
	mlx_destroy_image(env->prms.mlx, env->img.img);
	mlx_destroy_window(env->prms.mlx, env->prms.mlx_win);
	mlx_destroy_display(env->prms.mlx);
	free(env->prms.mlx);
	free_map(env->map);
	exit(1);
	return (0);
}
