/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hqureshi <hqureshi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 14:46:09 by hqureshi      #+#    #+#                 */
/*   Updated: 2022/11/18 15:26:15 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

#include <math.h>
#include <string.h>



void	hook(void * param)
{
	t_data *data;

  data = param;
  if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
  {
		data->posY -= 0.1;
    draw_floor_ceiling(data);
    draw_wall(data);
  }
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
  {
		data->posY += 0.1;
    draw_floor_ceiling(data);
    draw_wall(data);
  }
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
	{
    data->posX -= 0.1;
    draw_floor_ceiling(data);
    draw_wall(data);
  } 
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
  {
    data->posX += 0.1;
    draw_floor_ceiling(data);
    draw_wall(data);
  }
}

int main(void)
{
	t_data data;
	
  data.posX = 22;
  data.posY = 12;
	data.mlx = mlx_init(screenWidth, screenHeight, "Cub3d", true);
	data.mlx_image = mlx_new_image(data.mlx, screenWidth, screenHeight);
	mlx_image_to_window(data.mlx, data.mlx_image, 0, 0);
	mlx_loop_hook(data.mlx, &hook, &data);
  draw_floor_ceiling(&data);
  draw_wall(&data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
