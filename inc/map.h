/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 14:48:51 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/11/23 14:47:07 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../lib/mlx/include/MLX42/MLX42.h"
# include "cub3d.h"

// #define SCREENWIDTH 640
// #define SCREENHEIGHT 640
// #define MAPWIDTH 24
// #define MAPHEIGHT 24

#define SCREENWIDTH 1024
#define SCREENHEIGHT 512
#define MAPWIDTH 8
#define MAPHEIGHT 8
#define MAPSIZE 64

// typedef struct s_position {
//     int                 x;
//     int                 y;
//     struct s_position   *next;
// }              t_position;

typedef struct s_map {
    mlx_t       *mlx;
    mlx_image_t *mlx_image;
    mlx_image_t *background_image;
    mlx_image_t *player_image;
    mlx_image_t *ray;
    int         posX;
    int         posY;
    int         pfov;
    int         pdx;
    int         pdy;
    int         ratioX;
    int         ratioY;
    // t_position  *world_map;
}              t_map;

void    draw_top_view_grid(t_map *map);
void    draw_player(t_map *map);
void    raycast_y(t_map *map);
void    raycast_x(t_map *map);

void player_hook(void *param);

#endif