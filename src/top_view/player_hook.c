/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_hook.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 14:10:00 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/11/30 11:06:48 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void player_hook(void *param)
{
    double oldDirx;
    double oldPlaneX;
    t_map *map;

    map = param;
    oldDirx = map->dirX;
    oldPlaneX = map->planeX;
    mlx_delete_image(map->mlx, map->image);

    if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	else if (mlx_is_key_down(map->mlx, MLX_KEY_D)) // rotate right
    {
        map->dirX = map->dirX * cos(map->angle_increment) - map->dirY * sin(map->angle_increment);
        map->dirY = oldDirx * sin(map->angle_increment) + map->dirY * cos(map->angle_increment);
        map->planeX = map->planeX * cos(map->angle_increment) - map->planeY * sin(map->angle_increment);
        map->planeY = oldPlaneX * sin(map->angle_increment) + map->planeY * cos(0.1);
    }
    else if (mlx_is_key_down(map->mlx, MLX_KEY_A)) // rotate left
    {
        map->dirX = map->dirX * cos(-map->angle_increment) - map->dirY * sin(-map->angle_increment);
        map->dirY = oldDirx * sin(-0.1) + map->dirY * cos(-map->angle_increment);
        map->planeX = map->planeX * cos(-map->angle_increment) - map->planeY * sin(-map->angle_increment);
        map->planeY = oldPlaneX * sin(-map->angle_increment) + map->planeY * cos(-map->angle_increment);
    }
    else if (mlx_is_key_down(map->mlx, MLX_KEY_UP)) // move forward
    {
        map->posX -= map->dirX * 0.5;
        map->posY -= map->dirY * 0.5;
    }
    else if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN)) // move backwards
    {
        map->posX += map->dirX * 0.5;
        map->posY += map->dirY * 0.5;
    }
    map->image = mlx_new_image(map->mlx, SCREENWIDTH, SCREENHEIGHT);
    draw_top_view_grid(map);
    draw_player(map);
    // printf("point on ray (%f, %f)\n", map->posX * map->dirX, map->posY * map->dirY);
    draw_direction(map, map->posX * map->dirX, map->posY * map->dirY);
}