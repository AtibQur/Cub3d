/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:46:09 by hqureshi          #+#    #+#             */
/*   Updated: 2022/11/16 11:14:25 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

#include <math.h>
#include <string.h>

#define screenWidth 256
#define screenHeight 256
#define mapWidth 24
#define mapHeight 24

int main(void)
{
	t_data data;

	data.mlx = mlx_init(screenWidth, screenHeight, "Cub3d", true);
	if (!data.mlx)
		exit(EXIT_FAILURE);
	data.mlx_image = mlx_new_image(data.mlx, 128, 128);
	// memset(data.mlx_image->pixels, 255, data.mlx_image->width * data.mlx_image->height * sizeof(int));
	mlx_put_pixel(data.mlx_image, 100, 100, 0xFF0000FF);
	mlx_image_to_window(data.mlx, data.mlx_image, 0, 0);
	mlx_loop(data.mlx);

}
