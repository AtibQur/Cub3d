/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:31:13 by tvan-der          #+#    #+#             */
/*   Updated: 2022/12/06 14:41:59 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	hook(void *param)
{
    char	**map;
	t_data  *data;
    t_player *player;

	data = param;
	map = data->map.map;
	player = data->player;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
			mlx_close_window(data->mlx);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_left(map, player);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_right(map, player);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_forward(map, player);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_backward(map, player);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate_right(player);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate_left(player);
	draw_floor_ceiling(data);
	draw_wall(data);
}