/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hqureshi <hqureshi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 17:21:23 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/12/13 14:17:57 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	intersect(t_data *data, t_ray *ray)
{
	ray->deltadist_x = fabs(1 / ray->raydir_x);
	ray->deltadist_y = fabs(1 / ray->raydir_y);
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (data->player->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - data->player->pos_x)
			* ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (data->player->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - data->player->pos_y)
			* ray->deltadist_y;
	}
}

void	dda(char **map, t_ray *ray)
{
	if (ray->sidedist_x < ray->sidedist_y)
	{
		ray->sidedist_x += ray->deltadist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->sidedist_y += ray->deltadist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
	if (map[ray->map_y][ray->map_x] > '0')
		ray->hit = 1;
}

void	calculate_wall_height(t_ray *ray)
{
	if (ray->side == 0)
		ray->walldist = ray->sidedist_x - ray->deltadist_x;
	else
		ray->walldist = ray->sidedist_y - ray->deltadist_y;
	ray->lineheight = (int)(SCREENHEIGHT / ray->walldist);
	ray->drawstart = -ray->lineheight / 2 + SCREENHEIGHT / 2;
	ray->drawend = ray->lineheight / 2 + SCREENHEIGHT / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	if (ray->drawend >= SCREENHEIGHT)
		ray->drawend = SCREENHEIGHT - 1;
}
