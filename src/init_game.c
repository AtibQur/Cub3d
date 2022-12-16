/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:37:23 by hqureshi          #+#    #+#             */
/*   Updated: 2022/12/16 11:21:02 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_data *data, t_ray *ray)
{
	ray->camera_x = (2 * ray->column_x) / (double)SCREENWIDTH - 1;
	ray->raydir_x = data->player->dir_x + data->player->plane_x * ray->camera_x;
	ray->raydir_y = data->player->dir_y + data->player->plane_y * ray->camera_x;
	ray->map_x = (int)(data->player->pos_x);
	ray->map_y = (int)(data->player->pos_y);
	ray->hit = 0;
	if (ray->raydir_x == 0)
		ray->deltadist_x = 1e30;
	else
		ray->deltadist_x = fabs(1 / ray->raydir_x);
	if (ray->raydir_y == 0)
		ray->deltadist_y = 1e30;
	else
		ray->deltadist_y = fabs(1 / ray->raydir_y);
}

t_player	set_perspective(double dir_x, double dir_y,
	double plane_x, double plane_y)
{
	t_player	player;

	player.dir_x = dir_x;
	player.dir_y = dir_y;
	player.plane_x = plane_x;
	player.plane_y = plane_y;
	return (player);
}

t_player	init_player(t_data *data)
{
	t_player	player;

	if (data->map.player_dir == 'N')
		player = set_perspective(0.0, -1.0, 0.66, 0.0);
	else if (data->map.player_dir == 'E')
		player = set_perspective(1.0, 0.0, 0.0, 0.66);
	else if (data->map.player_dir == 'S')
		player = set_perspective(0.0, 1.0, -0.66, 0.0);
	else if (data->map.player_dir == 'W')
		player = set_perspective(-1.0, 0.0, 0.0, -0.66);
	player.pos_x = data->map.player_pos_x;
	player.pos_y = data->map.player_pos_y;
	player.move_speed = 0.05;
	player.rot_speed = 0.05;
	return (player);
}

void	init_data(t_data *data, char **argv)
{
	data->file_name = argv[1];
	data->map.f_color = 0;
	data->map.c_color = 0;
	data->map.map_start = 0;
	data->map.existing_player = 0;
	data->map.player_inside_walls = 0;
	data->map.player_dir = 0;
	data->minimap_image = mlx_new_image(data->mlx, SCREENWIDTH, SCREENHEIGHT);
}

void	init_game(t_data *data, int argc, char **argv)
{
	if (argc != 2)
		exit_game("Please use the right amount of arguments", 1);
	data->mlx = mlx_init(SCREENWIDTH, SCREENHEIGHT, "Cub3d", true);
	if (!data->mlx)
		exit_game("MLX failure", 1);
	data->mlx_image = mlx_new_image(data->mlx, SCREENWIDTH, SCREENHEIGHT);
	if (!data->mlx_image)
		exit_game("MLX_image failed", 1);
	init_data(data, argv);
}
