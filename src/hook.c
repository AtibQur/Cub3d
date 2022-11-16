/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 16:31:13 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/11/16 16:31:25 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	hook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		data->mlx_image->instances[0].y -= 5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		data->mlx_image->instances[0].y += 5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->mlx_image->instances[0].x -= 5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->mlx_image->instances[0].x += 5;
}