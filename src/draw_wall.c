/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:31:45 by hqureshi          #+#    #+#             */
/*   Updated: 2022/12/02 16:14:50 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../inc/cub3d.h"

// int worldMap[mapWidth][mapHeight]=
// {
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };

int worldMap[mapWidth][mapHeight] = 
{
  {1,1,1,1,1},
  {2,0,0,0,4},
  {2,0,0,0,4},
  {2,0,0,0,4},
  {3,3,3,3,3}
};

int	wall_collision(t_player *player)
{
  int map_x;
  int map_y;

  map_x = (int)(player->pos_x);
  map_y = (int)(player->pos_y);
  if (worldMap[map_x][map_y] == 0)
    return (0);
  else
    return (1);
}

void draw_floor_ceiling(t_data *data)
{
    int y = 0;

    while (y < screenHeight)
    {
        int x = 0;
        while (x < screenWidth)
        {
            if (y > (screenHeight / 2))
                mlx_put_pixel(data->mlx_image, x, y, 0xFF000000); //floor
            else
                mlx_put_pixel(data->mlx_image, x, y, 0xFF00FF00); //ceiling
                
            x++;
        }
        y++;
    }
}

void    draw_vertical_line(t_data *data, t_ray *ray)
{
    while (ray->drawstart < ray->drawend)
    {
      mlx_put_pixel(data->mlx_image, ray->column_x, ray->drawstart, ray->color);
      ray->drawstart++;
    }
}

void dda(t_ray *ray)
{
    int i = 0;
    if(ray->sidedist_x < ray->sidedist_y)
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
    if (worldMap[ray->map_x][ray->map_y] > 0) 
        ray->hit = 1;
    // printf("after iteration %d -> side distance x = %f & side distance y = %f\n", i, ray->sidedist_x, ray->sidedist_y);
    i++;
}

void    get_color(t_ray *ray)
{
    if (worldMap[ray->map_x][ray->map_y] == 1)
    {
      ray->color = RGB_RED;
      return ;
    }
    else if (worldMap[ray->map_x][ray->map_y] == 2)
    {
      ray->color = RGB_GREEN;
      return ;
    }
    else if (worldMap[ray->map_x][ray->map_y] == 3)
    {
      ray->color = RGB_BLUE;
      return ;
    }
    else if (worldMap[ray->map_x][ray->map_y] == 4)
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
	while (ray.column_x < screenWidth)  
	{
    // printf("------ for x: %d ------\n", ray.column_x);
    init_ray(data, &ray);
    intersect(player->pos_x, player->pos_y, &ray);
    while(ray.hit == 0)
      dda(&ray);
    // printf("side = %d\n", ray.side);
    // printf("after dda side distance x = %f & side distance y = %f\n", ray.sidedist_x, ray.sidedist_y);
    calculate_wall_height(&ray);
    // printf("drawstart = %d & drawend = %d\n", ray.drawstart, ray.drawend);
    get_color(&ray);
    // printf("color is %d\n\n", ray.color);
    draw_vertical_line(data, &ray);
    ray.column_x++;
  }
}
