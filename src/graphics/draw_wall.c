/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_wall.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hqureshi <hqureshi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 14:31:45 by hqureshi      #+#    #+#                 */
/*   Updated: 2022/12/08 17:36:20 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
      
mlx_texture_t *get_texture_image(t_data *data, t_ray *ray)
{
	if (ray->side == 0 && ray->step_x == 1)
		return (data->texture.no_texture);
	else if (ray->side == 0 && ray->step_x == -1)
		return (data->texture.so_texture);
	else if (ray->side == 1 && ray->step_x == 1)
		return (data->texture.ea_texture);
	else
		return (data->texture.we_texture);
}

int get_pixel_color(mlx_texture_t *texture, int x, int y)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
  unsigned int a;

  x %= texture->width;
  y %= texture->height;
	r = texture->pixels[y * texture->width * 4 + (x * 4)];
	g = texture->pixels[y * texture->width * 4 + (x * 4) + 1];
	b = texture->pixels[y * texture->width * 4 + (x * 4) + 2];
  a = texture->pixels[y * texture->width * 4 + (x * 4) + 3];
	return (r << 24 | g << 16 | b << 8 | a);
}

void    draw_texture(t_data *data, t_ray *ray)
{
    double wallX;
    mlx_texture_t *texture;
     
    texture = get_texture_image(data, ray);
    if (ray->side == 0)
      wallX = data->player->pos_y + ray->walldist * ray->raydir_y;
    else          
      wallX = data->player->pos_y + ray->walldist * ray->raydir_x;
    wallX -= floor((wallX));

    int texX = (int)(wallX * (double)(texture->width));
    if (ray->side == 0 && ray->raydir_x > 0)
      texX = texture->width - texX - 1;
    if (ray->side == 1 && ray->raydir_y < 0)
      texX = texture->width - texX - 1;

    double step = 1.0 * texture->height / ray->lineheight;
    double texPos = (ray->drawstart - SCREENHEIGHT / 2 + ray->lineheight / 2) * step;
    while (ray->drawstart < ray->drawend)
    {
      int texY = (int)texPos & (texture->height - 1);
      texPos += step;
      unsigned int color = get_pixel_color(texture, texY, texX);
      mlx_put_pixel(data->mlx_image, ray->column_x, ray->drawstart, color);
      ray->drawstart++;
    }
}

void    draw_wall(t_data *data)
{
  t_player  *player;
  t_ray     ray;

	player = data->player;
  ray.column_x = 0;
	while (ray.column_x < SCREENWIDTH)  
	{
    init_ray(data, &ray);
    intersect(data, &ray);
    while(ray.hit == 0)
      dda(data->map.map, &ray);
    calculate_wall_height(&ray);
    draw_texture(data, &ray);
    ray.column_x++;
  }
}
