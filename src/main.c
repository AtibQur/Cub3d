/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:46:09 by hqureshi          #+#    #+#             */
/*   Updated: 2022/11/22 14:46:04 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <math.h>
#include <string.h>

int main(int argc, char **argv)
{
	t_data data;
	
	init_game(&data, argc);
	parse_map(&data, argv[1]);
	// data.mlx_image = mlx_new_image(data.mlx, screenWidth, screenHeight);
	// mlx_image_to_window(data.mlx, data.mlx_image, 0, 0);
	// mlx_loop_hook(data.mlx, &hook, &data);
  	// draw_floor_ceiling(&data);
  	// draw_wall(&data);
	// mlx_loop(data.mlx);
	// mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
