/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hqureshi <hqureshi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 14:46:09 by hqureshi      #+#    #+#                 */
/*   Updated: 2022/11/16 16:28:39 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

#include <math.h>
#include <string.h>

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24


// int worldMap[mapWidth][mapHeight]=
// {
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };

// int main(void)
// {
// 	t_data data;

// 	data.mlx = mlx_init(screenWidth, screenHeight, "Cub3d", true);
// 	if (!data.mlx)
// 		exit(EXIT_FAILURE);
// 	data.mlx_image = mlx_new_image(data.mlx, 128, 128);
// 	// memset(data.mlx_image->pixels, 255, data.mlx_image->width * data.mlx_image->height * sizeof(int));
// 	mlx_put_pixel(data.mlx_image, 100, 100, 0xFF0000FF);
// 	mlx_image_to_window(data.mlx, data.mlx_image, 0, 0);
// 	mlx_loop(data.mlx);

// }

// void	hook(void *param)
// {
// 	t_data	*data;

// 	data = param;
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(data->mlx);
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
// 		data->mlx_image->instances[0].y -= 5;
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
// 		data->mlx_image->instances[0].y += 5;
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
// 		data->mlx_image->instances[0].x -= 5;
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
// 		data->mlx_image->instances[0].x += 5;
// }

// int main(void)
// {
// 	t_data data;
// 	double posX = 22, posY = 12;  //x and y start position
// 	double dirX = -1, dirY = 0; //initial direction vector
// 	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

// 	double time = 0; //time of current frame
// 	double oldTime = 0; //time of previous frame
// 	// data_init(&data);
	
// 	data.mlx = mlx_init(screenWidth, screenHeight, "Cub3d", true);
// 	data.mlx_image = mlx_new_image(data.mlx, screenWidth, screenHeight);

// 	for(int x = 0; x < data.mlx->width; x++)
// 	{
// 		double cameraX = 2 * x / (double)data.mlx->width - 1; //x-coordinate in camera space
//       	double rayDirX = dirX + planeX * cameraX;
//       	double rayDirY = dirY + planeY * cameraX;
//       	//which box of the map we're in
//       	int mapX = (posX);
//       	int mapY = (posY);

// 		//length of ray from current position to next x or y-side
//     	double sideDistX;
//     	double sideDistY;

// 		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
//     	double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
//       	double perpWallDist;

//       //what direction to step in x or y-direction (either +1 or -1)
//       int stepX;
//       int stepY;

//       int hit = 0; //was there a wall hit?
//       int side; //was a NS or a EW wall hit?
//       //calculate step and initial sideDist
//       if(rayDirX < 0)
//       {
//         stepX = -1;
//         sideDistX = (posX - mapX) * deltaDistX;
//       }
//       else
//       {
//         stepX = 1;
//         sideDistX = (mapX + 1.0 - posX) * deltaDistX;
//       }
//       if(rayDirY < 0)
//       {
//         stepY = -1;
//         sideDistY = (posY - mapY) * deltaDistY;
//       }
//       else
//       {
//         stepY = 1;
//         sideDistY = (mapY + 1.0 - posY) * deltaDistY;
//       }
// //perform DDA
//       while(hit == 0)
//       {
//         //jump to next map square, either in x-direction, or in y-direction
//         if(sideDistX < sideDistY)
//         {
//           sideDistX += deltaDistX;
//           mapX += stepX;
//           side = 0;
//         }
//         else
//         {
//           sideDistY += deltaDistY;
//           mapY += stepY;
//           side = 1;
//         }
//         //Check if ray has hit a wall
//         if(worldMap[mapX][mapY] > 0) hit = 1;
//       }
//       //Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
//       //hit to the camera plane. Euclidean to center camera point would give fisheye effect!
//       //This can be computed as (mapX - posX + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
//       //for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
//       //because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
//       //steps, but we subtract deltaDist once because one step more into the wall was taken above.
//       if(side == 0) perpWallDist = (sideDistX - deltaDistX);
//       else          perpWallDist = (sideDistY - deltaDistY);

//       //Calculate height of line to draw on screen
//       int lineHeight = (int)(data.mlx->height) / perpWallDist;

//       //calculate lowest and highest pixel to fill in current stripe
//       int drawStart = -lineHeight / 2 + data.mlx->height / 2;
//       if(drawStart < 0) drawStart = 0;
//       int drawEnd = lineHeight / 2 + data.mlx->height / 2;
//       if(drawEnd >= data.mlx->height) drawEnd = data.mlx->height - 1;

//       //choose wall color
// 	  int color;
//       switch(worldMap[mapX][mapY])
//       {
//         // case 1:  color = RGB_RED;    break; //red
//         // case 2:  color = 0x00FF00FF;  break; //green
//         // case 3:  color = 0x0000FFFF;   break; //blue
//         // case 4:  color = 0xFFFFFFFF;  break; //white
//         default: color = 0xFFFFFFFF; break; //yellow
//       }

//       //give x and y sides different brightness
//     //   if(side == 1) {color = color / 2;}

//       //draw the pixels of the stripe as a vertical line
//     //   verLine(x, drawStart, drawEnd, color);
// 	  mlx_put_pixel(data.mlx_image, drawStart, drawEnd, color);
//     }
// 	mlx_image_to_window(data.mlx, data.mlx_image, 0, 0);
// 	mlx_loop_hook(data.mlx, &hook, &data);
// 	mlx_loop(data.mlx);
// 	mlx_terminate(data.mlx);
// 	return (EXIT_SUCCESS);
// }
