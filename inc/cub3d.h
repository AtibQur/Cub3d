/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:48:29 by hqureshi          #+#    #+#             */
/*   Updated: 2022/12/16 10:57:52 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/mlx/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

# define SCREENWIDTH 860
# define SCREENHEIGHT 620

typedef struct s_map {
	char	**map;
	int		f_color;
	int		c_color;
	int		map_start;
	int		width;
	int		height;
	int		existing_player;
	int		player_inside_walls;
	char	player_dir;
	double	player_pos_x;
	double	player_pos_y;
}				t_map;

typedef struct s_texture {
	mlx_texture_t	*no_texture;
	mlx_texture_t	*so_texture;
	mlx_texture_t	*we_texture;
	mlx_texture_t	*ea_texture;
}				t_texture;

typedef struct s_tex_info {
	mlx_texture_t	*texture;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
}				t_tex_info;

typedef struct s_player {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	move_speed;
	double	rot_speed;
}				t_player;

typedef struct s_ray {
	int			column_x;
	int			map_x;
	int			map_y;
	int			hit;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			step_x;
	int			step_y;
	int			side;
	int			color;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	double		deltadist_x;
	double		deltadist_y;
	double		sidedist_x;
	double		sidedist_y;
	double		walldist;
}				t_ray;

typedef struct s_data {
	mlx_t		*mlx;
	mlx_image_t	*mlx_image;
	mlx_image_t	*minimap_image;
	t_map		map;
	t_texture	texture;
	t_player	*player;
	t_ray		ray;
	char		*img_addr;
	char		*file_name;
	char		*test;
	double		step;
	int			copy_map_i;
	int			copy_map_j;
	int			element_count;
}				t_data;

// initialize all game info
void		init_data(t_data *data, char **argv);
void		init_game(t_data *data, int argc, char **argv);
void		init_ray(t_data *data, t_ray *ray);
t_player	init_player(t_data *data);

// hook
void		hook(void *param);
void		move_backward(char **map, t_player *player);
void		move_forward(char **map, t_player *player);
void		move_left(char **map, t_player *player);
void		move_right(char **map, t_player *player);
void		rotate(t_player *player, double rot_speed);

// drawing
void		draw_wall(t_data *data);
void		draw_floor_ceiling(t_data *data);

//raycast
void		intersect(t_data *data, t_ray *ray);
void		dda(char **map, t_ray *ray);
void		calculate_wall_height(t_ray *ray);

//applying textures
void		draw_texture(t_data *data, t_ray *ray);

// parse all incoming data
void		parse_map(t_data *data);
void		start_parsing(t_data *data, t_map *map, int fd);
void		read_map(t_data *data, t_map *map, int fd);
void		copy_map_chars(t_map *map, char c, int *k, int i);
int			player_pos(t_data *data, char *line, int j);
int			add_player_pos(t_map *map, char c, int *k, int i);
void		copy_map_chars(t_map *map, char c, int *k, int i);

// load all textures
void		no_wall(t_data *data, char *str);
void		so_wall(t_data *data, char *str);
void		we_wall(t_data *data, char *str);
void		ea_wall(t_data *data, char *str);

// white space functions
char		*skip_whitespace(char *line);
bool		ft_is_whitespace(char c);
char		*erase_whitespace(char *line);

// error management
int			check_correct_values(char *line);
void		check_walls(t_data *data);
void		check_cub_extension(char *map);
void		check_elements(t_data *data, int fd);
void		check_width_height(t_map *map, int fd, char *line);

//  save wall and floor/ceiling data
int			rgb_color(int r, int g, int b);
int			save_wall_textures(t_data *data, char *line);
int			floor_and_ceiling_textures(t_data *data, char *line);
int			find_len_color(char *line);

// exit function
void		exit_game(char *str, int exit_num);

#endif
