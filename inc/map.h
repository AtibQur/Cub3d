/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:48:51 by tvan-der          #+#    #+#             */
/*   Updated: 2022/12/02 16:27:11 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef MAP_H
// # define MAP_H

// # include "../lib/mlx/include/MLX42/MLX42.h"
// # include "cub3d.h"


// // #define SCREENWIDTH 640
// // #define SCREENHEIGHT 640
// // #define MAPWIDTH 24
// // #define MAPHEIGHT 24

// #define SCREENWIDTH 1024
// #define SCREENHEIGHT 512
// #define MAPWIDTH 8
// #define MAPHEIGHT 8
// #define MAPSIZE 64

// typedef struct s_map {
//     mlx_t       *mlx;
//     mlx_image_t *image;
//     double         posX;
//     double         posY;
//     double         pfov;
//     double         pdx;
//     double         pdy;
//     double         dirX;
//     double         dirY;
//     double         planeX;
//     double         planeY;
//     double         angle_increment;
// }              t_map;

// //data init
// void    data_init(t_map *map);

// //draw functions
// void    draw_top_view_grid(t_map *map);
// void    draw_player(t_map *map);
// void    draw_direction(t_map *map, int dest_x, int dest_y);

// //hook
// void    player_hook(void *param);

// //utils
// int     deg_to_rad(int num);

// #endif