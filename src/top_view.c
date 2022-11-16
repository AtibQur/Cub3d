/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   top_view.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 16:24:58 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/11/16 17:16:15 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

#include <math.h>
#include <string.h>

#define screenWidth 500
#define screenHeight 500
#define mapWidth 5
#define mapHeight 5

// 1 block = 500/5 = 100 pixels

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1},
  {1,0,0,0,1},
  {1,0,0,0,1},
  {1,0,0,0,1},
  {1,1,1,1,1},
};

void    draw_top_view(t_data *data)
{
    int     x;
    int     y;
    int     ratio;

    ratio = screenHeight / mapHeight; // or screenweight/mapweight = 100 
    y = 0;
    while (y < screenHeight)
    {
        x = 0;
        while (x < screenWidth)
        {
            if (worldMap[x / ratio][y / ratio] == 1) //wall
                mlx_put_pixel(data->mlx_image, x, y, 0xffffff);
            else if (worldMap[x / ratio][y / ratio] == 0) //open space
                mlx_put_pixel(data->mlx_image, x, y, 0x000000);
            else if (x % ratio == 0 || y % ratio == 0) //gridborder
                mlx_put_pixel(data->mlx_image, x, y, 0x808080);
            x++;
        }
        y++;
    }
}

int main()
{
    t_data data;
    
    data.mlx = mlx_init(screenWidth, screenHeight, "Cub3d", true);
	data.mlx_image = mlx_new_image(data.mlx, screenWidth, screenHeight);
    draw_top_view(&data);
    // mlx_put_pixel(data.mlx_image, 250, 250, 0x808080);
    mlx_image_to_window(data.mlx, data.mlx_image, 0, 0);
	mlx_loop_hook(data.mlx, &hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}