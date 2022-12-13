/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_floor_ceiling.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: hqureshi <hqureshi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 14:24:55 by hqureshi      #+#    #+#                 */
/*   Updated: 2022/12/13 14:14:43 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor_ceiling(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREENHEIGHT)
	{
		x = 0;
		while (x < SCREENWIDTH)
		{
			if (y > (SCREENHEIGHT / 2))
				mlx_put_pixel(data->mlx_image, x, y, data->map.c_color);
			else
				mlx_put_pixel(data->mlx_image, x, y, data->map.f_color);
			x++;
		}
		y++;
	}
}
