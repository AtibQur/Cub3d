/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:46:09 by hqureshi          #+#    #+#             */
/*   Updated: 2022/12/16 11:39:02 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data		data;
	t_player	player;

	init_game(&data, argc, argv);
	parse_map(&data);
	player = init_player(&data);
	data.player = &player;
	draw_floor_ceiling(&data);
	draw_wall(&data);
	mlx_image_to_window(data.mlx, data.mlx_image, 0, 0);
	mlx_loop_hook(data.mlx, &hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	system("leaks cub3D");
	return (EXIT_SUCCESS);
}
