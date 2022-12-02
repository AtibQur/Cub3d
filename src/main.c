/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hqureshi <hqureshi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 14:46:09 by hqureshi      #+#    #+#                 */
/*   Updated: 2022/12/02 14:42:44 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

#include <math.h>
#include <string.h>

// double deg_to_rad(double num)
// {
//     return (num * (M_PI / 180.0));
// }

int main(void)
{
	t_data data;
	t_player player;
	
	init_data(&data);
	player = init_player(&data);
	data.player = &player;
	mlx_image_to_window(data.mlx, data.mlx_image, 0, 0);
  	draw_floor_ceiling(&data);
  	draw_wall(&data);
	mlx_loop_hook(data.mlx, &hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
