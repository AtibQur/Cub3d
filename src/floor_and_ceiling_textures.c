/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceiling_textures.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:44:54 by hqureshi          #+#    #+#             */
/*   Updated: 2022/12/14 17:29:28 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int has 4 bytes
// 24 << is 4, 16 << is 3, 8 << is 2, 0 << 1
// every value gets stored in the int and creates the color outcome
int	rgb_color(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit_game("Invalid color value", 1);
	return (r << 24 | g << 16 | b << 8 | 255);
}

int	find_len_color(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (!ft_is_whitespace(line[i]))
			count++;
		i++;
	}
	return (count);
}

int	get_color(char *line)
{
	int	r;
	int	g;
	int	b;

	r = 0;
	g = 0;
	b = 0;
	line = erase_whitespace(line + 1);
	r = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line++;
	g = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line++;
	b = ft_atoi(line);
	return (rgb_color(r, g, b));
}

// Check if floor and ceiling values are correct
// Create the color of the floor and ceiling with RGB
int	floor_and_ceiling_textures(t_data *data, char *line)
{
	while (*line == ' ')
		line++;
	if (*line == 'F' && *(line + 1) == ' ')
		data->map.f_color = get_color(line);
	else if (*line == 'C' && *(line + 1) == ' ')
		data->map.c_color = get_color(line);
	else
		exit_game("Error within floor and ceiling values", 1);
	return (1);
}
