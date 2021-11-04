/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:45:38 by user42@stud       #+#    #+#             */
/*   Updated: 2021/11/03 16:00:29 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

void	load_image(t_env *env, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(env->prms.mlx, path, \
	&(img->width), &(img->height));
	if (img->img)
		img->addr = mlx_get_data_addr(img->img, &(img->bppi), \
		&(img->line), &(img->endian));
}

void	draw_texture(t_env *env, int x, int y, t_img *img)
{
	unsigned int	color;
	int				i;
	int				j;
	float			ratio_y;
	float			ratio_x;

	i = 0;
	j = 0;
	while (j < env->bppe)
	{
		ratio_y = ((j / (float)env->bppe) * img->width);
		while (i < env->bppe)
		{
			ratio_x = ((i / (float)env->bppe) * img->height);
			color = index_color((int)ratio_x, (int)ratio_y, img);
			if (color != 0xFF000000)
				my_mlx_pixel_put(&(env->img), i + x, j + y, color);
			i++;
		}
		i = 0;
		j++;
	}
}

void	init_col(int *x, int *y, int *i, int *j)
{
	*i = 0;
	*j = 0;
	*x = 0;
	*y = 0;
}

unsigned int	index_color(int x, int y, t_img *img)
{
	return (*(unsigned int *)(img->addr + \
		(y * img->line + x * (img->bppi / 8))));
}

void	load_all_images(t_env *env)
{
	load_image(env, &(env->wall), "texture/wall_essaie_recadrer_64.xpm");
	load_image(env, &(env->grass), "texture/grass.xpm");
	load_image(env, &(env->ruby), "texture/ruby.xpm");
	load_image(env, &(env->door), "texture/door.xpm");
	load_image(env, &(env->link_down1), "texture/link_m.xpm");
	load_image(env, &(env->link_down2), "texture/link_m2.xpm");
	load_image(env, &(env->link_right1), "texture/link_right1.xpm");
	load_image(env, &(env->link_right2), "texture/link_right2.xpm");
	load_image(env, &(env->link_left1), "texture/link_left1.xpm");
	load_image(env, &(env->link_left2), "texture/link_left2.xpm");
	load_image(env, &(env->link_up1), "texture/link_up1.xpm");
	load_image(env, &(env->link_up2), "texture/link_up2.xpm");
}
