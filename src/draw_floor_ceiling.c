/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:24:55 by hqureshi          #+#    #+#             */
/*   Updated: 2022/11/28 11:24:27 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_floor_ceiling(t_data *data)
{
    int y = 0;

    while (y < screenHeight)
    {
        int x = 0;
        while (x < screenWidth)
        {
            if (y > (screenHeight / 2))
                mlx_put_pixel(data->mlx_image, x, y, data->map.c_color);
            else
                mlx_put_pixel(data->mlx_image, x, y, data->map.f_color);
            x++;
        }
        y++;
    }
}
