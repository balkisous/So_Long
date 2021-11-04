/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:00:51 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/11/04 12:17:57 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../mlx/mlx.h"
#include <stdbool.h>

# define KEY_ESC 65307
/*
# define KEY_W 119	//up
# define KEY_A 97	//left
# define KEY_S 115	//down
# define KEY_D 100	//right
*/

# define KEY_W 65362	//up
# define KEY_A 65361	//left
# define KEY_S 65364	//down
# define KEY_D 65363	//right

typedef struct	s_prms
{
	void *mlx;
	void *mlx_win;
}				t_prms;

typedef struct	s_pos
{
	int	pos_x;
	int	pos_y;
}				t_pos;	

typedef struct s_img
{
	void	*img;
	char 	*addr;
	int		bppi;
	int		line;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_env
{
	char		**map;
	int			height;
	int			width;
	int			bppe;
	int			step;
	int			count_col;
	int			key;
	t_prms		prms;
	t_img		img;
	t_img		wall;
	t_img		grass;
	t_img		ruby;
	t_img		door;
	t_img		link_down1;
	t_img		link_down2;
	t_img		link_right1;
	t_img		link_right2;
	t_img		link_left1;
	t_img		link_left2;
	t_img		link_up1;
	t_img		link_up2;
	t_pos		b_player;
	t_pos		player;
	t_pos		p_move;
}				t_env;

typedef struct	s_param
{
	int		c;
	int		e;
	int		p;
	int		size_x;
	int		size_y;
	int		nb_of_lines;
	char	**map;
}				t_param;

///////get_next_line.c
int		ft_strclen(char *str, char c);
char	*ft_strndup(char *str, int n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_str_ret(char **ret_str);
char	*get_next_line(int fd, t_param *param, bool first_read);
char	*copy(char *s1, int *i, char *ret);

///////parsing.c

int ft_pars_name(char *str);
int ft_parse_arg(int argc, char **argv);
int	ft_size_tab(char **map);
int	is_one(char *str, char c);
int check_one(char **map, t_param *p);

/////parsing_map.c
void	ft_init(t_param *p, char **map);
int		ft_parsing(char **map, t_param *p);
int		ft_strlen(char *str);
int		ft_size_map(char **map);
int		check_size_tab(char **map, t_param *p);
int		ft_check_one(char **map, t_param *p);
int		ft_find(char *str, char c);
int		check_char(char **map);
int		ft_count(char **map, t_param *p);


//////draw_pixel_2.c

void		ft_window(char **map, int width, int height, int coll);
int			draw_one_square(t_env *env, int x, int y, int color);
void		init_env(t_env *env, char **map, int width, int height);
void		move_player(t_env *env);


//////draw_map.c
void	draw_map(t_env *env);
int		prev_move(int keypress, t_env *env);
int		is_wall(t_env *env, int prev, char c);
void	get_pos_p(t_pos *object, char **map);
void	draw_coll_and_player(t_env *env);
int		add(int *x, int *y, int *i, int *j);
void	init_col(int *x, int *y, int *i, int *j);



//////main.c
void	ft_free(char **map);

//////main_utils.c
int		open_fd(int fd, char **argv);
void    read_file(int fd, t_param *p);
int		ft_len_malloc(t_param *p);
void	store_map(t_param *p, int fd);
void	secure_line(char *line);


//////mlx_utils.c
int			create_trgb(int t, int r, int g, int b);
int			show_image(t_env *env);
//int			press_key(int keypress, t_env *env);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
int			release_key(int keypress, t_env *env);

//////count.c
void	define_place(t_env *env);
void	print_exit(t_env *env);
void	move_p(t_env *env);
void	move(t_env *env);
void	move2(t_env *env);

//////draw_texture.c
void			load_image(t_env *env, t_img *img, char *path);
void			draw_texture(t_env *env, int x, int y, t_img *img);
unsigned int	index_color(int x, int y, t_img *img);
void			load_all_images(t_env *env);

/////exit_game.c
int		quit_game(t_env *env);
void	destroy_all_images(t_env *env);
void	destroy_image(t_env *env, t_img *img);

void	free_map(char **map);

# endif
