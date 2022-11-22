/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:37:23 by hqureshi          #+#    #+#             */
/*   Updated: 2022/11/22 15:26:05 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_data(t_data *data)
{
	// data->posX = 22;
	// data->posY = 12;
	// data->dirX = -1;
	// data->dirY = 0;
	// data->planeX = 0;
	// data->planeY = 0.66;
	// data->hit = 0;
	data->file.no_wall = 0;
	data->file.so_wall = 0;
	data->file.we_wall = 0;
	data->file.ea_wall = 0;
	data->file.f_color = 0;
	data->file.c_color = 0;
}

void    init_game(t_data *data, int argc)
{
    if (argc != 2)
        exit_game("Please use the right amount of arguments", 1);
    data->mlx = mlx_init(screenWidth, screenHeight, "Cub3d", true);
    if (!data->mlx)
        exit_game("MLX failure", 1);
    init_data(data);
}
