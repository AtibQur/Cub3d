/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:48:29 by hqureshi          #+#    #+#             */
/*   Updated: 2022/11/23 14:17:27 by hqureshi         ###   ########.fr       */
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

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

enum color {
    RGB_RED = 0xFF0000FF,
    RGB_GREEN = 0x00FF00FF,
    RGB_BLUE = 0x0000FFFF,
    RGB_WHITE = 0xFFFFFFFF,
};

typedef struct s_file {
    char        **map;
    char        no_wall;
    char        so_wall;
    char        we_wall;
    char        ea_wall;
    int         f_color;
    int         c_color;
}       t_file;

typedef struct s_data {
    mlx_t       *mlx;
    mlx_image_t *mlx_image;
    // mlx_texture *mlx_texture;
    // mlx_image_t *background_image;
    // mlx_image_t *player_image;
    // int         posX;
    // int         posY;
    t_file      file;
    int         mapX;
    int         mapY;
    int         hit;
    int         lineHeight;
    double      posX;
    double      posY;
    double      dirX;
    double      dirY;
    double      planeX;
    double      planeY;
    double      cameraX;
    
}       t_data;

// main
int		main(int argc, char **argv);

// draw functions
void draw_wall(t_data *data);
void draw_floor_ceiling(t_data *data);

// key hook functions
void	hook(void *param);

// initialize all game info
void    init_data(t_data *data);
void    init_game(t_data *data, int argc);

// parse all incoming data
int     return_double(int num);
void    parse_map(t_data *data, char *map);
void    start_parsing(t_data *data, int fd);

// error management
void    check_cub_extension(char *file);
int     check_correct_values(char *line);
void    check_elements(t_data *data, int fd);

//  save wall and floor/ceiling data
int     save_wall_textures(t_data *data, char *line);
void	floor_and_ceiling_textures(t_data *data, char *line);

// exit function
void    exit_game(char *str, int exit_num);

#endif
