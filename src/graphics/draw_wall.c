/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:31:45 by hqureshi          #+#    #+#             */
/*   Updated: 2022/12/07 11:02:07 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    draw_vertical_line(t_data *data, t_ray *ray)
{
    while (ray->drawstart < ray->drawend)
    {
      mlx_put_pixel(data->mlx_image, ray->column_x, ray->drawstart, ray->color);
      ray->drawstart++;
    }
}

void    get_color(char **map, t_ray *ray)
{
  //  printf("for %d map[%d][%d] == %c\n", ray->column_x, ray->map_y, ray->map_x, map[ray->map_y][ray->map_x]);
   if (map[ray->map_y][ray->map_x] == '1')
    {
      ray->color = RGB_RED;
      return ;
    }
    else if (map[ray->map_y][ray->map_x] == '2')
    {
      ray->color = RGB_GREEN;
      return ;
    }
    else if (map[ray->map_y][ray->map_x] == '3')
    {
      ray->color = RGB_BLUE;
      return ;
    }
    else if (map[ray->map_y][ray->map_x] == '4')
    {
      ray->color = RGB_WHITE;
      return ;
    }
}

void    draw_wall(t_data *data)
{
  t_player  *player;
  t_ray     ray;

	player = data->player;
  ray.column_x = 0;
	while (ray.column_x < SCREENWIDTH)  
	{
    init_ray(data, &ray);
    // printf("for %d at map[%d][%d] = %c\n", ray.column_x, ray.map_x, ray.map_y, data->map.map[ray.map_y][ray.map_x]);
    intersect(data, &ray);
    while(ray.hit == 0)
      dda(data->map.map, &ray);
    calculate_wall_height(&ray);
    get_color(data->map.map, &ray);
    if (ray.side == 1) 
      ray.color = ray.color / 2;
    draw_vertical_line(data, &ray);
    ray.column_x++;
  }
}
