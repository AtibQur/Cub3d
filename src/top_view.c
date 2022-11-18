/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   top_view.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 16:24:58 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/11/18 15:29:02 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

#include <math.h>
#include <string.h>

#define screenWidth 640
#define screenHeight 640
#define mapWidth 20
#define mapHeight 20

// 1 block = 500/5 = 100 pixels

// int worldMap[mapWidth][mapHeight]=
// {
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,1},
//   {1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,0,1},
//   {1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,0,1},
//   {1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,0,1},
//   {1,0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
// };

// void    draw_top_view_grid(t_data *data)
// {
//     int     x;
//     int     y;
//     int     ratioX;
//     int     ratioY;

//     ratioX = screenWidth / mapWidth; // or screenweight/mapweight = 100 
//     ratioY = screenHeight / mapHeight; // or screenweight/mapweight = 100 
//     y = 0;
//     while (y < screenHeight)
//     {
//         x = 0;
//         while (x < screenWidth)
//         {
//             if (worldMap[x / ratioX][y / ratioY] == 1) //wall
//                 mlx_put_pixel(data->background_image, x, y, 0xffffffff);
//             else if (worldMap[x / ratioX][y / ratioY] == 0) //open space
//                 mlx_put_pixel(data->background_image, x, y, 0x00000000);
//             if (x % ratioX == 0 || y % ratioY == 0) //gridborder
//                 mlx_put_pixel(data->background_image, x, y, 0x80808080);
//             x++;
//         }
//         y++;
//     }
// }

// void    draw_player(t_data *data)
// {
//     int x;
//     int y;
//     y = 0;
//     while (y < 2)
//     {
//         x = 0;
//         while (x < 2)
//         {
//             mlx_put_pixel(data->background_image, 350 + x, 350 + y, 0xffffffff);
//             x++;
//         }
//         y++;
//     }
// }

// int main()
// {
//     t_data data;
    
//     data.mlx = mlx_init(screenWidth, screenHeight, "Cub3d", true);
// 	data.background_image = mlx_new_image(data.mlx, screenWidth, screenHeight);
// 	data.player_image = mlx_new_image(data.mlx, 2, 2);
//     draw_top_view_grid(&data);
//     mlx_image_to_window(data.mlx, data.background_image, 0, 0);
//     draw_player(&data);
//     mlx_image_to_window(data.mlx, data.player_image, 0, 0);
// 	mlx_loop_hook(data.mlx, &hook, &data);
// 	mlx_loop(data.mlx);
// 	mlx_terminate(data.mlx);
// 	return (EXIT_SUCCESS);
// }