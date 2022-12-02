/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:37:23 by hqureshi          #+#    #+#             */
/*   Updated: 2022/12/02 17:32:00 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_ray(t_data *data, t_ray *ray)
{
    ray->camera_x = 2 * ray->column_x / (double)SCREENWIDTH - 1;
    ray->raydir_x = data->player->dir_x + data->player->plane_x * ray->camera_x;
    ray->raydir_y = data->player->dir_y + data->player->plane_y * ray->camera_x;
    printf("ray camera = %f\n", ray->camera_x);
    printf("player dir x = %f & dir y = %f\n", data->player->dir_x, data->player->dir_y);
    printf("player plane x = %f & plane y = %f\n", data->player->plane_x, data->player->plane_y);
    printf("ray dir x = %f & dir y = %f\n\n", ray->raydir_x, ray->raydir_y);
    ray->map_x = (int)(data->player->pos_x);
    ray->map_y = (int)(data->player->pos_y);
    ray->deltadist_x = (ray->raydir_x == 0) ? 1e30 : fabs(1 / ray->raydir_x);
    ray->deltadist_y = (ray->raydir_y == 0) ? 1e30 : fabs(1 / ray->raydir_y);
    ray->hit = 0;
    printf("delta distance x = %f & delta distance y = %f\n", ray->deltadist_x, ray->deltadist_y);
}

t_player init_player(t_data *data)
{
    t_player player;
    //based on input pos char (N,S,E,W) initialize variables accordingly
    player.pos_x = 2.5;
    player.pos_y = 2.5;
    // player.pos_x = data->map.player_pos_x;
    // player.pos_y = data->map.player_pos_y;
    if (data->map.player_dir == 'N')
    {
        player.dir_x = 0;
        player.dir_y = -1;
        player.plane_x = 0.66;
        player.plane_y = 0;
    }
    else if (data->map.player_dir == 'E')
    {
        player.dir_x = 1;
        player.dir_y = 0;
        player.plane_x = 0;
        player.plane_y = 0.66;
    }
    else if (data->map.player_dir == 'S')
    {
        player.dir_x = 0;
        player.dir_y = 1;
        player.plane_x = 0;
        player.plane_y = 0.66;
    }
    else if (data->map.player_dir == 'W')
    {
        player.dir_x = -1;
        player.dir_y = 0;
        player.plane_x = 0;
        player.plane_y = 0.66;
    }
    return (player);
}

void    init_data(t_data *data, char **argv)
{
    data->file_name = argv[1];
	data->map.f_color = 0;
	data->map.c_color = 0;
    data->map.map_start = 0;
    data->map.existing_player = 0;
    data->map.player_inside_walls = 0;
    data->map.player_dir = 0;
}

void    init_game(t_data *data, int argc, char **argv)
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
