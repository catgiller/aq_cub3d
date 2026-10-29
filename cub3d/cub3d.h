/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervsahin <ervsahin@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:21:47 by ervsahin          #+#    #+#             */
/*   Updated: 2026/08/12 17:43:07 by ervsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <math.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define MOVE_SPEED 0.08
# define ROT_SPEED 0.05

# define NO_ID	1
# define SO_ID	2
# define WE_ID	3
# define EA_ID	4
# define FLOOR_ID 5
# define CEILING_ID 6
# define TILE_SIZE 16

# define TEX_NO 0
# define TEX_SO 1
# define TEX_WE 2
# define TEX_EA 3

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_textures
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_textures;

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}	t_color;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_tex
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_tex;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	wall_x;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_id;
	int		tex_x;
}	t_ray;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_mlx;

typedef struct s_game
{
	t_map		map;
	t_textures	textures;
	t_player	player;
	t_color		floor;
	t_color		ceiling;
	int			floor_set;
	int			ceiling_set;
	t_mlx		mlx;
	t_tex		tex[4];
	int			key_w;
	int			key_s;
	int			key_a;
	int			key_d;
	int			key_left;
	int			key_right;
}	t_game;

typedef struct s_flood
{
	char	**map;
	int		*stack;
	int		width;
	int		height;
	int		top;
	int		closed;
}	t_flood;

void	print_error(char *message);
void	set_game(t_game *game);
void	set_line(char *line);
int		check_file_extension(char *file_name);
void	parser(t_game *game, char *file);
void	read_file(int fd, t_game *game);
char	*extract_path(char *line);
char	*skip_whitespace(char *line);
int		get_identifier(char *line);
void	parse_texture(char *line, t_game *game);
void	store_texture(t_game *game, int id, char *path);
int		check_texture_file(char *path);
int		read_number(char **line, int *value);
void	init_game(t_game *game);
int		get_color_identifier(char *line);
void	parse_color(char *line, t_game *game);
void	store_color(t_game *game, int id, t_color color);
int		extract_rgb(char *line, t_color *color);
void	check_config_complete(t_game *game);
int		parse_map(t_game *game, char *first_map_line, int fd);
int		is_empty_line(char *line);
char	**read_map_lines(char *first_map_line, int fd, int *height);
int		calculate_map_width(char **map);
int		store_map(t_game *game, char **map, int width, int height);
void	free_map(char **map, int height);
void	free_game(t_game *game);
void	parse_map_validation(t_game *game);
void	validate_map_enclosed(t_game *game);
void	validate_walkable_enclosed(t_game *game);
int		is_player_char(char c);
void	init_mlx(t_game *game);
int		close_game(void *param);
int		handle_keypress(int keycode, void *param);
int		handle_keyrelease(int keycode, void *param);
void	handle_movement(t_game *game);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		render_frame(void *param);
void	init_player(t_game *game);
void	load_textures(t_game *game);
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);
void	cast_rays(t_game *game);
void	init_ray(t_game *game, t_ray *ray, int x);
void	calc_step(t_game *game, t_ray *ray);
void	perform_dda(t_game *game, t_ray *ray);
void	calc_wall_height(t_game *game, t_ray *ray);
void	choose_texture(t_game *game, t_ray *ray);
void	draw_wall_stripe(t_game *game, t_ray *ray, int x);
void	draw_background(t_game *game);

#endif
