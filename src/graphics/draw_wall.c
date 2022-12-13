/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_wall.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hqureshi <hqureshi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 14:31:45 by hqureshi      #+#    #+#                 */
/*   Updated: 2022/12/13 14:20:35 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_wall(t_data *data)
{
	t_ray		ray;
	t_player	*player;

	player = data->player;
	ray.column_x = 0;
	while (ray.column_x < SCREENWIDTH)
	{
		init_ray(data, &ray);
		intersect(data, &ray);
		while (ray.hit == 0)
			dda(data->map.map, &ray);
		calculate_wall_height(&ray);
		draw_texture(data, &ray);
		ray.column_x++;
	}
}
