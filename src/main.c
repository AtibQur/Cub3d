/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:46:09 by hqureshi          #+#    #+#             */
/*   Updated: 2022/12/02 15:43:19 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_data data;

	init_game(&data, argc, argv);
	parse_map(&data);
	// data.mlx_image = mlx_new_image(data.mlx, screenWidth, screenHeight);
	// mlx_image_to_window(data.mlx, data.mlx_image, 0, 0);
	// mlx_loop_hook(data.mlx, &hook, &data);
  	// draw_floor_ceiling(&data);
	// mlx_loop(data.mlx);
	// mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
