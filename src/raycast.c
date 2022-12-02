/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 17:21:23 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/12/02 14:46:20 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void intersect(double pos_x, double pos_y, t_ray *ray)
{
    if(ray->raydir_x < 0)
    {
      ray->step_x = -1;
      ray->sidedist_x = (pos_x - ray->map_x) * ray->deltadist_x;
    }
    else
    {
      ray->step_x = 1;
      ray->sidedist_x = (ray->map_x + 1.0 - pos_x) * ray->deltadist_x;
    }
    if(ray->raydir_y < 0)
    {
        ray->step_y = -1;
        ray->sidedist_y = (pos_y - ray->map_y) * ray->deltadist_y;
    }
    else
    {
        ray->step_y = 1;
        ray->sidedist_y = (ray->map_y + 1.0 - pos_y) * ray->deltadist_y;
    }
    // printf("after step side distance x = %f & side distance y = %f\n", ray->sidedist_x, ray->sidedist_y);
}

// void dda(t_ray *ray)
// {
//     if(ray->sidedist_x < ray->sidedist_y)
//     {
//         ray->sidedist_x += ray->deltadist_x;
//         ray->map_x += ray->step_x;
//         ray->side = 0;
//     }
//     else
//     {
//         ray->sidedist_y += ray->deltadist_y;
//         ray->map_y += ray->step_y;
//         ray->side = 1;
//     }
//     if (worldMap[ray->map_x][ray->map_y] > 0) 
//         ray->hit = 1;
// }

void    calculate_wall_height(t_ray *ray)
{
    if (ray->side == 0) 
       ray->walldist = ray->sidedist_x - ray->deltadist_x;
    else
      ray->walldist = ray->sidedist_y - ray->deltadist_y;
    // printf("wall distance = %f\n", ray->walldist);
    ray->lineheight = (int)screenHeight / ray->walldist;
    // printf("line height = %d\n", ray->lineheight);
    ray->drawstart = -ray->lineheight / 2 + screenHeight / 2;
    ray->drawend = ray->lineheight / 2 + screenHeight / 2;
    if (ray->drawstart < 0)
      ray->drawstart = 0;
    if (ray->drawend >= screenHeight)
      ray->drawend = screenHeight - 1;
}

