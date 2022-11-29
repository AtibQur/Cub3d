/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:48:29 by hqureshi          #+#    #+#             */
/*   Updated: 2022/11/29 14:46:18 by hqureshi         ###   ########.fr       */
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
# include <memory.h>
# include <fcntl.h>
# include <string.h>

# define screenWidth 640
# define screenHeight 480
# define mapWidth 24
# define mapHeight 24

enum color {
    RGB_RED = 0xFF0000FF,
    RGB_GREEN = 0x00FF00FF,
    RGB_BLUE = 0x0000FFFF,
    RGB_WHITE = 0xFFFFFFFF,
};

typedef struct s_map {
    char        **map;
    int         f_color;
    int         c_color;
    int         map_start;
    int         width;
    int         height;
}       t_map;

typedef struct s_texture {
    mlx_texture_t   *no_texture;
    mlx_texture_t   *so_texture;
    mlx_texture_t   *we_texture;
    mlx_texture_t   *ea_texture;
}       t_texture;

typedef struct s_data {
    mlx_t       *mlx;
    mlx_image_t *mlx_image;
    // mlx_texture *mlx_texture;
    // mlx_image_t *background_image;
    // mlx_image_t *player_image;
    // int         posX;
    // int         posY;
    t_map       map;
    t_texture   texture;
    char        *file_name;

    char        *test;
}       t_data;

// main
int		main(int argc, char **argv);

// draw functions
void    draw_wall(t_data *data);
void    draw_floor_ceiling(t_data *data);

// key hook functions
void	hook(void *param);

// initialize all game info
void    init_data(t_data *data, char **argv);
void    init_game(t_data *data, int argc, char **argv);

// parse all incoming data
int     return_double(int num);
void    parse_map(t_data *data);
void    start_parsing(t_data *data, t_map *map, int fd);
void    copy_map(t_data *data, t_map *map, int fd);
void    copy_map_chars(t_map *map, char c, int *k, int i);

// error management
void    check_cub_extension(char *map);
int     check_correct_values(char *line);
void    check_elements(t_data *data, int fd);
void    check_width_height(t_map *map, int fd, char *line);

//  save wall and floor/ceiling data
int     rgb_color(int r, int g, int b);
int     save_wall_textures(t_data *data, char *line);
void    color_floor(t_data *data, char *line);
void	color_ceiling(t_data *data, char *line);
void	floor_and_ceiling_textures(t_data *data, char *line);

// exit function
void    exit_game(char *str, int exit_num);

#endif
