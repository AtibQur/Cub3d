/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:37:23 by hqureshi          #+#    #+#             */
/*   Updated: 2022/12/02 13:39:17 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_data(t_data *data, char **argv)
{
    data->file_name = argv[1];
	data->map.f_color = 0;
	data->map.c_color = 0;
    data->map.map_start = 0;
    data->map.existing_player = 0;
    data->map.player_inside_walls = 0;
}

void    init_game(t_data *data, int argc, char **argv)
{
    if (argc != 2)
        exit_game("Please use the right amount of arguments", 1);
    data->mlx = mlx_init(screenWidth, screenHeight, "Cub3d", true);
    if (!data->mlx)
        exit_game("MLX failure", 1);
    init_data(data, argv);
}
