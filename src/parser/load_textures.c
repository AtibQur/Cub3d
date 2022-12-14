/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:27:52 by hqureshi          #+#    #+#             */
/*   Updated: 2022/12/14 10:28:06 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	no_wall(t_data *data, char *str)
{
	data->texture.no_texture = mlx_load_png(str);
	if (data->texture.no_texture == 0)
		exit_game("Wrong texture path.", 1);
}

void	so_wall(t_data *data, char *str)
{
	data->texture.so_texture = mlx_load_png(str);
	if (data->texture.so_texture == 0)
		exit_game("Wrong texture path.", 1);
}

void	we_wall(t_data *data, char *str)
{
	data->texture.we_texture = mlx_load_png(str);
	if (data->texture.we_texture == 0)
		exit_game("Wrong texture path.", 1);
}

void	ea_wall(t_data *data, char *str)
{
	data->texture.ea_texture = mlx_load_png(str);
	if (data->texture.ea_texture == 0)
		exit_game("Wrong texture path.", 1);
}
