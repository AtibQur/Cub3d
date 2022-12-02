/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hqureshi <hqureshi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 11:38:10 by hqureshi      #+#    #+#                 */
/*   Updated: 2022/12/02 14:45:48 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// void	init_ray_to_zero(t_ray *ray) // is this needed?
// {
// 	ray->column_x = 0;
// 	ray->map_x = 0;
// 	ray->map_y = 0;
// 	ray->hit = 0;
//  	ray->lineheight = 0;
// 	ray->drawstart = 0;
// 	ray->drawend = 0;
// 	ray->color = 0;
// 	ray->step_x = 0;
// 	ray->step_y = 0;
// 	ray->side = 0;
// 	ray->raydir_x = 0;
//  	ray->raydir_y = 0;
// 	ray->deltadist_x = 0;
// 	ray->deltadist_y = 0;
// 	ray->sidedist_x = 0;
//     ray->sidedist_y = 0;
// 	ray->walldist = 0;
// }

void	init_ray(t_data *data, t_ray *ray)
{
	ray->camera_x = 2 * ray->column_x / (double)screenWidth - 1;
    ray->raydir_x = data->player->dir_x + data->player->plane_x * ray->camera_x;
    ray->raydir_y = data->player->dir_y + data->player->plane_y * ray->camera_x;
	// printf("ray camera = %f\n", ray->camera_x);
	// printf("player dir x = %f & dir y = %f\n", data->player->dir_x, data->player->dir_y);
	// printf("player plane x = %f & plane y = %f\n", data->player->plane_x, data->player->plane_y);
	// printf("ray dir x = %f & dir y = %f\n\n", ray->raydir_x, ray->raydir_y);
    ray->map_x = (int)(data->player->pos_x);
    ray->map_y = (int)(data->player->pos_y);
	ray->deltadist_x = (ray->raydir_x == 0) ? 1e30 : fabs(1 / ray->raydir_x);
    ray->deltadist_y = (ray->raydir_y == 0) ? 1e30 : fabs(1 / ray->raydir_y);
	ray->hit = 0;
	// printf("delta distance x = %f & delta distance y = %f\n", ray->deltadist_x, ray->deltadist_y);
}

t_player init_player(t_data *data)
{
	t_player player;
	
	//based on input pos char (N,S,E,W) initialize variables accordingly
	player.pos_x = 2.5;
	player.pos_y = 2.5;
	if (data->player_dir == 'N')
	{
		player.dir_x = 0;
		player.dir_y = -1;
		player.plane_x = 0.66;
		player.plane_y = 0;
	}
	else if (data->player_dir == 'E')
	{
		player.dir_x = 1;
		player.dir_y = 0;
		player.plane_x = 0;
		player.plane_y = 0.66;
	}
	else if (data->player_dir == 'S')
	{
		player.dir_x = 0;
		player.dir_y = 1;
		player.plane_x = 0;
		player.plane_y = 0.66;
	}
	else if (data->player_dir == 'W')
	{
		player.dir_x = -1;
		player.dir_y = 0;
		player.plane_x = 0;
		player.plane_y = 0.66;
	}
	else // default ! delete!!
	{
		player.dir_x = 0;
		player.dir_y = -1;
		player.plane_x = 0.66;
		player.plane_y = 0;
	}

	return (player);
}

void    init_data(t_data *data)
{
	data->mlx = mlx_init(screenWidth, screenHeight, "Cub3d", true);
	data->mlx_image = mlx_new_image(data->mlx, screenWidth, screenHeight);
	// data->floor_color = ;
	// data->ceiling_color = ;
	// data->player_dir = ;
}