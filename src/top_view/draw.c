/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 14:10:52 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/11/30 11:06:50 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

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

int worldMap[MAPHEIGHT][MAPWIDTH] =
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

// bool    hit_wall_check(t_map *map, int x, int y)
// {
//     if (worldMap[x / MAPSIZE][y / MAPSIZE] == 1)
//         return (true);
//     return (false);
// }

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
                mlx_put_pixel(map->image, x, y, 0xffffffff);
            else if (worldMap[y / MAPSIZE][x / MAPSIZE] == 0) //open space
                mlx_put_pixel(map->image, x, y, 0x00000000);
            if (x % MAPSIZE == 0 || y % MAPSIZE == 0) //gridborder
                mlx_put_pixel(map->image, x, y, 0x80808080);
            x++;
        }
        y++;
    }
    mlx_image_to_window(map->mlx, map->image, 0, 0);
}

void    draw_player(t_map *map)
{
    double x;
    double y;
    
    y = 0;
    while (y < 2)
    {
        x = 0;
        while (x < 2)
        {
            mlx_put_pixel(map->image, map->posX + x, map->posY + y, RGB_RED);
            x++;
        }
        y++;
    }
    mlx_image_to_window(map->mlx, map->image, 0, 0);
}

void    draw_direction(t_map *map, int dest_x, int dest_y)
{
    int current_x = map->posX;
    int current_y = map->posY;
    int dx = abs(dest_x - current_x);
    int sx = current_x < dest_x ? 1 : -1;
    int dy = abs(dest_y - current_y);
    int sy = current_y < dest_y ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    while (1) 
    {
        if (current_x == dest_x && current_y == dest_y)
            break;
        e2 = err;
        if (e2 > -dx) {
            err -= dy;
            current_x += sx;
        }
        if (e2 < dy) {
            err += dx;
            current_y += sy;
        }
        if (worldMap[current_y / MAPSIZE][current_x / MAPSIZE] == 0
                && (current_x >= 0 && current_x < SCREENWIDTH / 2)
                && (current_y >= 0 && current_x < SCREENHEIGHT))
        {
            printf("point on ray (%d, %d)\n", current_x, current_y);
            mlx_put_pixel(map->image, current_x, current_y, RGB_GREEN);
        }
        else
            break;
            
    }
}
