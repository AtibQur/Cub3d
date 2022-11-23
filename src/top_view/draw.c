/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 14:10:52 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/11/23 14:34:30 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

// void    draw_top_view_grid(t_map *map)
// {
//     int     x;
//     int     y;
    
//     y = 0;
//     while (y < SCREENHEIGHT)
//     {
//         x = 0;
//         while (x < SCREENWIDTH / 2)
//         {
//             if (worldMap[y / MAPSIZE][x / MAPSIZE] == 1) //wall
//                 mlx_put_pixel(map->background_image, x, y, 0xffffffff);
//             else if (worldMap[y / MAPSIZE][x / MAPSIZE] == 0) //wall
//                 mlx_put_pixel(map->background_image, x, y, 0x00000000);
//             if (x % MAPSIZE == 0 || y % MAPSIZE == 0) //gridborder
//                 mlx_put_pixel(map->background_image, x, y, 0x80808080);
//             x++;
//         }
//         y++;
//     }
//     mlx_image_to_window(map->mlx, map->background_image, 0, 0);
// }

// void    draw_top_view_grid(t_map *map)
// {
//     int     x;
//     int     y;
    
//     y = 0;
//     while (y < SCREENHEIGHT)
//     {
//         x = 0;
//         while (x < SCREENWIDTH)
//         {
//             if (world_map[y / map->ratioY][x / map->ratioX] == 1) //wall
//                 mlx_put_pixel(map->background_image, x, y, 0xffffffff);
//             else if (world_map[y / map->ratioY][x / map->ratioX] == 0) //wall
//                 mlx_put_pixel(map->background_image, x, y, 0x00000000);
//             if (x % map->ratioX == 0 || y % map->ratioY == 0) //gridborder
//                 mlx_put_pixel(map->background_image, x, y, 0x80808080);
//             x++;
//         }
//         y++;
//     }
//     mlx_image_to_window(map->mlx, map->background_image, 0, 0);
// }

void    draw_player(t_map *map)
{
    int x;
    int y;
    
    y = 0;
    while (y < 2)
    {
        x = 0;
        while (x < 2)
        {
            mlx_put_pixel(map->background_image, map->posX + x, map->posY + y, RGB_RED);
            x++;
        }
        y++;
    }
    mlx_image_to_window(map->mlx, map->player_image, 0, 0);
}

// void raycast_y(t_map *map)
// {
//     int y;

//     y = 0;
//     while(world_map[map->posX / map->ratioX][(map->posY + y)/ map->ratioY] != 1)
//     {
//         mlx_put_pixel(map->background_image, map->posX, map->posY + y, RGB_GREEN); 
//         y++;
//     }
//     mlx_image_to_window(map->mlx, map->ray, 0, 0);
// }

// void raycast_x(t_map *map)
// {
//     int x;

//     x = 0;
//     while(world_map[(map->posX + x) / map->ratioX][map->posY/ map->ratioY] != 1)
//     {
//         mlx_put_pixel(map->ray, map->posX + x, map->posY, RGB_GREEN); 
//         x++;
//     }
//     mlx_image_to_window(map->mlx, map->ray, 0, 0);
// }

