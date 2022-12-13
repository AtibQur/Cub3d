/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/13 14:20:17 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/12/13 14:20:39 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_texture_t	*get_texture(t_data *data, t_ray *ray)
{
	if (ray->side == 0 && ray->step_x == 1)
		return (data->texture.we_texture);
	else if (ray->side == 0 && ray->step_x == -1)
		return (data->texture.ea_texture);
	else if (ray->side == 1 && ray->step_y == 1)
		return (data->texture.no_texture);
	return (data->texture.so_texture);
}

unsigned int	get_pixel_color(mlx_texture_t *texture, int x, int y)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	a;

	r = texture->pixels[y * texture->width * 4 + (x * 4)];
	g = texture->pixels[y * texture->width * 4 + (x * 4) + 1];
	b = texture->pixels[y * texture->width * 4 + (x * 4) + 2];
	a = texture->pixels[y * texture->width * 4 + (x * 4) + 3];
	return (r << 24 | g << 16 | b << 8 | a);
}

int	get_tex_x(t_data *data, t_ray *ray, mlx_texture_t *texture)
{
	int		tex_x;
	double	wall_x;

	tex_x = 0;
	if (ray->side == 0)
		wall_x = data->player->pos_y + ray->walldist * ray->raydir_y;
	else
		wall_x = data->player->pos_x + ray->walldist * ray->raydir_x;
	wall_x -= floor((wall_x));
	tex_x = (int)(wall_x * (double)(texture->width));
	if (ray->side == 0 && ray->raydir_x > 0)
		tex_x = texture->width - tex_x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

void	get_tex_info(t_data *data, t_ray *ray, t_tex_info *tex)
{
	tex->texture = get_texture(data, ray);
	tex->tex_x = get_tex_x(data, ray, tex->texture);
	tex->tex_y = 0;
	tex->step = 1.0 * tex->texture->height / ray->lineheight;
	tex->tex_pos = ((double)ray->drawstart - (double)SCREENHEIGHT
			/ 2.0 + (double)ray->lineheight / 2.0) * tex->step;
}

void	draw_texture(t_data *data, t_ray *ray)
{
	int			y;
	t_tex_info	tex;

	get_tex_info(data, ray, &tex);
	y = ray->drawstart;
	while (y < ray->drawend)
	{
		tex.tex_y = (int)tex.tex_pos & (tex.texture->height - 1);
		ray->color = get_pixel_color(tex.texture, tex.tex_x, tex.tex_y);
		mlx_put_pixel(data->mlx_image, ray->column_x, y, ray->color);
		tex.tex_pos += tex.step;
		y++;
	}
}