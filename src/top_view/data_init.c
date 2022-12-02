/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_init.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/29 14:09:52 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/11/30 12:22:19 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void    data_init(t_map *map)
{
    map->posX = 300;
    map->posY = 300;
    map->dirX = cos(map->pfov);
    map->dirY = sin(map->pfov);
    map->planeX = 0;
    map->planeY = 0.66;
    map->pfov = M_PI / 2; //in radians
    map->angle_increment = map->pfov / SCREENWIDTH;
    map->pdx = cos(deg_to_rad(map->pfov));
    map->pdy = -sin(deg_to_rad(map->pfov));
    map->mlx = mlx_init(SCREENWIDTH, SCREENHEIGHT, "Cub3d", false);
	map->image = mlx_new_image(map->mlx, SCREENWIDTH, SCREENHEIGHT);
}