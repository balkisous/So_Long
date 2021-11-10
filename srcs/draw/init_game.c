/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:40:04 by user42@stud       #+#    #+#             */
/*   Updated: 2021/11/10 11:25:21 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

void	move_player(t_env *env)
{
	draw_texture(env, env->player.pos_x * env->bppe, \
	env->player.pos_y * env->bppe, &(env->grass));
	if (env->map[env->p_move.pos_y][env->p_move.pos_x] == 'C' && env->count_col)
	{
		env->map[env->p_move.pos_y][env->p_move.pos_x] = '0';
		env->count_col--;
	}
	define_place(env);
	print_exit(env);
	env->step++;
	move_p(env);
	if (env->map[env->player.pos_y][env->player.pos_x] == 'E'\
	&& !env->count_col)
	{
		printf("You win! Goodbye!\n");
		quit_game(env);
	}
	printf("step %d\n", env->step);
}

int	draw_one_square(t_env *env, int x, int y, int color)
{
	int	tmp;
	int	tmp_y;

	tmp = 0;
	tmp_y = 0;
	while (tmp_y < env->bppe)
	{
		tmp = 0;
		while (tmp < env->bppe)
		{
			my_mlx_pixel_put(&(env->img), x + tmp, y + tmp_y, color);
			tmp++;
		}
		tmp_y++;
	}
	return (0);
}

void	init_env(t_env *env, char **map, int width, int height)
{
	env->map = map;
	env->bppe = 64;
	env->height = height;
	env->width = width - 1;
	env->step = 0;
	get_pos_p(&(env->player), env->map);
	get_pos_p(&(env->p_move), env->map);
}

void	ft_window(char **map, int width, int height, int coll)
{
	t_env	env;

	init_env(&env, map, width, height);
	env.count_col = coll;
	env.prms.mlx = mlx_init();
	mlx_get_screen_size(env.prms.mlx, &env.img.width, &env.img.height);
	env.prms.mlx_win = mlx_new_window(env.prms.mlx, env.width * env.bppe, \
	env.height * env.bppe, "Welcome to so_long World!");
	env.img.img = mlx_new_image(env.prms.mlx, env.width * env.bppe, \
	env.height * env.bppe);
	env.img.addr = mlx_get_data_addr(env.img.img, &env.img.bppi, &env.img.line, \
	&env.img.endian);
	load_all_images(&env);
	draw_map(&env);
	env.height = height;
	env.width = width - 1;
	draw_coll_and_player(&env);
	mlx_key_hook(env.prms.mlx_win, release_key, &env);
	mlx_hook(env.prms.mlx_win, 33, 1L << 17, quit_game, &env);
	mlx_put_image_to_window(env.prms.mlx, env.prms.mlx_win, env.img.img, 0, 0);
	mlx_loop_hook(env.prms.mlx, show_image, &env);
	mlx_loop(env.prms.mlx);
}
