/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hqureshi <hqureshi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 16:24:58 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/11/23 15:22:45 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "map.h"
#include <math.h>
#include <string.h>

// int worldMap[MAPHEIGHT][MAPWIDTH]=
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

int worldMap[MAPHEIGHT][MAPWIDTH]=
{
  {1,1,1,1,1,1,1,1},
  {1,0,0,0,1,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,1,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1},
};


bool    hit_wall_check(t_map *map, int x, int y)
{
    if (worldMap[x / map->ratioX][y / map->ratioX] == 1)
        return (true);
    return (false);
}

void    draw_top_view_grid(t_map *map)
{
    int     x;
    int     y;
    
    y = 0;
    while (y < SCREENHEIGHT)
    {
        x = 0;
        while (x < SCREENWIDTH / 2)
        {
            if (worldMap[y / MAPSIZE][x / MAPSIZE] == 1) //wall
                mlx_put_pixel(map->background_image, x, y, 0xffffffff);
            else if (worldMap[y / MAPSIZE][x / MAPSIZE] == 0) //wall
                mlx_put_pixel(map->background_image, x, y, 0x00000000);
            if (x % MAPSIZE == 0 || y % MAPSIZE == 0) //gridborder
                mlx_put_pixel(map->background_image, x, y, 0x80808080);
            x++;
        }
        y++;
    }
    mlx_image_to_window(map->mlx, map->background_image, 0, 0);
}

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
//             if (worldMap[y / map->ratioY][x / map->ratioX] == 1) //wall
//                 mlx_put_pixel(map->background_image, x, y, 0xffffffff);
//             else if (worldMap[y / map->ratioY][x / map->ratioX] == 0) //wall
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
            mlx_put_pixel(map->player_image, map->posX + x, map->posY + y, RGB_RED);
            x++;
        }
        y++;
    }
    mlx_image_to_window(map->mlx, map->player_image, 0, 0);
}

void player_hook(void *param)
{
    t_map *map;

    map = param;
    if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	else if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
    {
        // if (hit_wall_check(map, map->posX - 1, map->posY))
        //     return ;
        map->posX -= 1;
        // draw_top_view_grid(map);
        // draw_player(map);
        // raycast_y(map);
    }
    else if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
    {
        // if (hit_wall_check(map, map->posX + 1, map->posY))
        //     return ;
        map->posX += 1;
        // draw_top_view_grid(map);
        // draw_player(map);
        // raycast_y(map);
    }
    else if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
    {
        // if (hit_wall_check(map, map->posX, map->posY - 1))
        //     return ;
        map->posY -= 1;
        // draw_top_view_grid(map);
        // draw_player(map);
        // raycast_y(map);
    } 
    else if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
    {
        // if (hit_wall_check(map, map->posX, map->posY + 1))
        //     return ;
        map->posY += 1;
        // draw_top_view_grid(map);
        // raycast_y(map);

    }
    draw_top_view_grid(map);
    draw_player(map);
}


int main()
{   
    t_map map;
    
    map.posX = 300;
    map.posY = 300;
    map.pfov = 60;
    // map.pdx = cos(deg_to_rad(map.pfov));
    // map.pdy = -sin(deg_to_rad(map.pfov));
    
    map.ratioX = SCREENWIDTH / MAPWIDTH; // or SCREENweight/mapweight = 100 
    map.ratioY = SCREENHEIGHT / MAPHEIGHT; // or SCREENweight/mapweight = 100 
    map.mlx = mlx_init(SCREENWIDTH, SCREENHEIGHT, "Cub3d", true);
	map.background_image = mlx_new_image(map.mlx, SCREENWIDTH, SCREENHEIGHT);
	// map.player_image = mlx_new_image(map.mlx, 2, 2);
	map.player_image = mlx_new_image(map.mlx, SCREENWIDTH, SCREENHEIGHT);
	// map.ray = mlx_new_image(map.mlx, SCREENWIDTH, SCREENHEIGHT);
    draw_top_view_grid(&map);
    draw_player(&map);
    // // raycast_x(&map);
    // raycast_y(&map);
	mlx_loop_hook(map.mlx, &player_hook, &map.mlx);
	mlx_loop(map.mlx);
	mlx_terminate(map.mlx);
	return (EXIT_SUCCESS);
}