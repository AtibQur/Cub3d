/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:31:13 by tvan-der          #+#    #+#             */
/*   Updated: 2022/12/02 16:15:27 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	hook(void *param)
{
    t_data   *data;
    t_player *player;

	data = param;
	player = data->player;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
			mlx_close_window(data->mlx);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		player->pos_x -= player->dir_y * 0.1;
		player->pos_y += player->dir_x * 0.1;
	}
		else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		player->pos_x += player->dir_y * 0.1;
		player->pos_y -= player->dir_x * 0.1;
	}
		else if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		{
		player->pos_x += player->dir_x * 0.1;
		player->pos_y += player->dir_y * 0.1;
	} 
		else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		player->pos_x -= player->dir_x * 0.1;
		player->pos_y -= player->dir_y * 0.1;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		double olddir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(-0.1) - player->dir_y * sin(-0.1);
		player->dir_y = olddir_x * sin(-0.1) + player->dir_y * cos(-0.1);
		double oldplane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(-0.1) - player->plane_y * sin(-0.1);
		player->plane_y = oldplane_x * sin(-0.1) + player->plane_y * cos(-0.1);
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		double olddir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(0.1) - player->dir_y * sin(0.1);
		player->dir_y = olddir_x * sin(0.1) + player->dir_y * cos(0.1);
		double oldplane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(0.1) - player->plane_y * sin(0.1);
		player->plane_y = oldplane_x * sin(0.1) + player->plane_y * cos(0.1);
	}
	draw_floor_ceiling(data);
	draw_wall(data);
}