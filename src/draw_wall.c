/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_wall.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hqureshi <hqureshi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 14:31:45 by hqureshi      #+#    #+#                 */
/*   Updated: 2022/11/21 11:38:21 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void draw_floor_ceiling(t_data *data)
{
    int y = 0;

    while (y < screenHeight)
    {
        int x = 0;
        while (x < screenWidth)
        {
            if (y > (screenHeight / 2))
                mlx_put_pixel(data->mlx_image, x, y, 0xFF000000);
            else
                mlx_put_pixel(data->mlx_image, x, y, 0xFF00FF00);
                
            x++;
        }
        y++;
    }
}

void draw_wall(t_data *data)
{
	double dirX = -1, dirY = 0; //initial direction vector
	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

	// double time = 0; //time of current frame
	// double oldTime = 0; //time of previous frame
    
    for(int x = 0; x < data->mlx->width; x++)
	{
        // printf("posx = \"%f\" posY = \"%f\"\n", data->posX, data->posY);
		double cameraX = 2 * x / (double)data->mlx->width - 1; //x-coordinate in camera space
      	double rayDirX = dirX + planeX * cameraX;
      	double rayDirY = dirY + planeY * cameraX;
      	//which box of the map we're in
      	data->mapX = (int)(data->posX);
      	data->mapY = (int)(data->posY);

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
        sideDistX = (data->posX - data->mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (data->mapX + 1.0 - data->posX) * deltaDistX;
      }
      if(rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (data->posY - data->mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (data->mapY + 1.0 - data->posY) * deltaDistY;
      }
//perform DDA
      while(hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if(sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          data->mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          data->mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if(worldMap[data->mapX][data->mapY] > 0) hit = 1;
      }
      if(side == 0) perpWallDist = (sideDistX - deltaDistX);
      else          perpWallDist = (sideDistY - deltaDistY);

      //Calculate height of line to draw on screen
      int lineHeight = (int)(data->mlx->height) / perpWallDist;

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + data->mlx->height / 2;
      if(drawStart < 0) drawStart = 0;
      int drawEnd = lineHeight / 2 + data->mlx->height / 2;
      if(drawEnd >= data->mlx->height) drawEnd = data->mlx->height - 1;

      //choose wall color
	  int color;
      switch(worldMap[data->mapX][data->mapY])
      {
        case 1:  color = RGB_RED;    break; //red  
        case 2:  color = RGB_GREEN;  break; //green
        case 3:  color = RGB_BLUE;   break; //blue
        case 4:  color = RGB_WHITE;  break; //white
      }

      //give x and y sides different brightness
      if(side == 1) {color = color / 2;}

      //draw the pixels of the stripe as a vertical line
    //   verLine(x, drawStart, drawEnd, color);
        while (drawStart < drawEnd)
        {
	        mlx_put_pixel(data->mlx_image, x, drawStart, color);
            drawStart++;
        }
    }
    
}