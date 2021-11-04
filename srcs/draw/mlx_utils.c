/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:44:31 by user42            #+#    #+#             */
/*   Updated: 2021/11/03 16:02:22 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

int	release_key(int keypress, t_env *env)
{
	if (keypress == KEY_ESC)
		quit_game(env);
	else if (keypress == KEY_D || keypress == KEY_S
		|| keypress == KEY_A || keypress == KEY_W)
	{
		env->key = keypress;
		if (prev_move(keypress, env))
			move_player(env);
	}
	return (1);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line + x * (img->bppi / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	show_image(t_env *env)
{
	mlx_put_image_to_window(env->prms.mlx, \
	env->prms.mlx_win, env->img.img, 0, 0);
	return (1);
}

int	prev_move(int keypress, t_env *env)
{
	if (keypress == KEY_D)
		return (is_wall(env, 1, 'x'));
	if (keypress == KEY_S)
		return (is_wall(env, 1, 'y'));
	if (keypress == KEY_A)
		return (is_wall(env, -1, 'x'));
	if (keypress == KEY_W)
		return (is_wall(env, -1, 'y'));
	return (0);
}
