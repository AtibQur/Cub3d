/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:31:13 by tvan-der          #+#    #+#             */
/*   Updated: 2022/11/21 14:37:39 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// void	hook(void *param)
// {
// 	t_data	*data;

// 	data = param;
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(data->mlx);
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
// 		data->player_image->instances[0].y -= 5;
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
// 		data->player_image->instances[0].y += 5;
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
// 		data->player_image->instances[0].x -= 5;
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
// 		data->player_image->instances[0].x += 5;
// }

void	hook(void * param)
{
	t_data *data;

  data = param;
  if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
  {
		// data->posY -= 0.1;
    data->posX -= data->dirY * 0.1;
    data->posY += data->dirX * 0.1;
    draw_floor_ceiling(data);
    draw_wall(data);
  }
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
  {
		// data->posY += 0.1;
    data->posX += data->dirY * 0.1;
    data->posY -= data->dirX * 0.1;
    draw_floor_ceiling(data);
    draw_wall(data);
  }
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
	{
    // data->posX -= 0.1;
    data->posX += data->dirX * 0.1;
    data->posY += data->dirY * 0.1;
    draw_floor_ceiling(data);
    draw_wall(data);
  } 
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
  {
    // data->posX += 0.1;
    data->posX -= data->dirX * 0.1;
    data->posY -= data->dirY * 0.1;
    draw_floor_ceiling(data);
    draw_wall(data);
  }
  if (mlx_is_key_down(data->mlx, MLX_KEY_D))
  {
		double oldDirx = data->dirX;
    data->dirX = data->dirX * cos(-0.1) - data->dirY * sin(-0.1);
    data->dirY = oldDirx * sin(-0.1) + data->dirY * cos(-0.1);
    double oldPlaneX = data->planeX;
    data->planeX = data->planeX * cos(-0.1) - data->planeY * sin(-0.1);
    data->planeY = oldPlaneX * sin(-0.1) + data->planeY * cos(-0.1);
    draw_floor_ceiling(data);
    draw_wall(data);
  }
  if (mlx_is_key_down(data->mlx, MLX_KEY_A))
  {
		double oldDirx = data->dirX;
    data->dirX = data->dirX * cos(0.1) - data->dirY * sin(0.1);
    data->dirY = oldDirx * sin(0.1) + data->dirY * cos(0.1);
    double oldPlaneX = data->planeX;
    data->planeX = data->planeX * cos(0.1) - data->planeY * sin(0.1);
    data->planeY = oldPlaneX * sin(0.1) + data->planeY * cos(0.1);
    draw_floor_ceiling(data);
    draw_wall(data);
  }
}