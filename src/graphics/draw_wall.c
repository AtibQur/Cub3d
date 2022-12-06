/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:31:45 by hqureshi          #+#    #+#             */
/*   Updated: 2022/12/06 14:51:22 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// int	wall_collision(t_player *player)
// {
//   int map_x;
//   int map_y;

//   map_x = (int)(player->pos_x);
//   map_y = (int)(player->pos_y);
//   if (map[map_x][map_y] == 0)
//     return (0);
//   else
//     return (1);
// }

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
  //  printf("for map[%d][%d] = %c\n", ray->map_x, ray->map_y, map[ray->map_x][ray->map_y]);
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
  // init_ray_to_zero(&ray);
    while (ray.column_x < SCREENWIDTH)  
    {
      // printf("------ for x: %d ------\n", ray.column_x);
      init_ray(data, &ray);
      intersect(data, &ray);
      // while(ray.hit == 0)
        dda(data->map.map, &ray);
      // printf("side = %d\n", ray.side);
      // printf("after dda side distance x = %f & side distance y = %f\n", ray.sidedist_x, ray.sidedist_y);
      calculate_wall_height(&ray);
      // printf("drawstart = %d & drawend = %d\n", ray.drawstart, ray.drawend);
      get_color(data->map.map, &ray);
      if (ray.side == 0)
        ray.color = ray.color / 2;
      // printf("color is %d\n\n", ray.color);
      draw_vertical_line(data, &ray);
      ray.column_x++;
    }
}
