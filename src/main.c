/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hqureshi <hqureshi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 14:46:09 by hqureshi      #+#    #+#                 */
/*   Updated: 2022/11/16 14:38:42 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

#include <math.h>
#include <string.h>

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

int main(void)
{
	t_data data;
	double posX = 22, posY = 12;  //x and y start position
	double dirX = -1, dirY = 0; //initial direction vector
	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

	double time = 0; //time of current frame
	double oldTime = 0; //time of previous frame
	// data_init(&data);
	
	data.mlx = mlx_init(screenWidth, screenHeight, "Cub3d", true);
	data.mlx_image = mlx_new_image(data.mlx, 128, 128);

	for(int x = 0; x < mapWidth; x++)
	{
		double cameraX = 2 * x / (double)mapWidth - 1; //x-coordinate in camera space
      	double rayDirX = dirX + planeX * cameraX;
      	double rayDirY = dirY + planeY * cameraX;
      	//which box of the map we're in
      	int mapX = (posX);
      	int mapY = (posY);

		//length of ray from current position to next x or y-side
    	double sideDistX;
    	double sideDistY;

		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
    	double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?
      //calculate step and initial sideDist
      if(rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      }
      if(rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
      }
//perform DDA
      while(hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if(sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if(worldMap[mapX][mapY] > 0) hit = 1;
      }
      //Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
      //hit to the camera plane. Euclidean to center camera point would give fisheye effect!
      //This can be computed as (mapX - posX + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
      //for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
      //because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
      //steps, but we subtract deltaDist once because one step more into the wall was taken above.
      if(side == 0) perpWallDist = (sideDistX - deltaDistX);
      else          perpWallDist = (sideDistY - deltaDistY);

      //Calculate height of line to draw on screen
      int lineHeight = (screenHeight) / perpWallDist;

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + screenHeight / 2;
      if(drawStart < 0) drawStart = 0;
      int drawEnd = lineHeight / 2 + screenHeight / 2;
      if(drawEnd >= screenHeight) drawEnd = screenHeight - 1;

      //choose wall color
	  int color;
      switch(worldMap[mapX][mapY])
      {
        case 1:  color = RGB_RED;    break; //red
        case 2:  color = RGB_GREEN;  break; //green
        case 3:  color = RGB_BLUE;   break; //blue
        case 4:  color = RGB_WHITE;  break; //white
        default: color = RGB_YELLOW; break; //yellow
      }

      //give x and y sides different brightness
      if(side == 1) {color = color / 2;}

      //draw the pixels of the stripe as a vertical line
    //   verLine(x, drawStart, drawEnd, color);
	  mlx_put_pixel(data.mlx_image, drawStart, drawEnd, color);
    }

	mlx_image_to_window(data.mlx, data.mlx_image, 0, 0);
	mlx_loop(data.mlx);
  
}
