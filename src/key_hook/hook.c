/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:31:13 by tvan-der          #+#    #+#             */
/*   Updated: 2022/12/07 11:02:55 by hqureshi         ###   ########.fr       */
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

	mlx_delete_image(data->mlx, data->mlx_image);
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
		rotate(player, player->move_speed);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate(player, -player->move_speed);
	data->mlx_image = mlx_new_image(data->mlx, SCREENWIDTH, SCREENHEIGHT);
    if (!data->mlx_image)
        exit_game("MLX_image failed", 1);
	draw_floor_ceiling(data);
	draw_wall(data);
	mlx_image_to_window(data->mlx, data->mlx_image, 0, 0);
}