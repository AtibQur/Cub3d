/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floor_and_ceiling_textures.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hqureshi <hqureshi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 10:44:54 by hqureshi      #+#    #+#                 */
/*   Updated: 2022/12/13 13:32:26 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int has 4 bytes
// 24 << is 4, 16 << is 3, 8 << is 2, 0 << 1
// every value gets stored in the int and creates the color outcome
// int	rgb_color(int r, int g, int b)
// {
// 	return (r << 24 | g << 16 | b << 8 | 255);
// }

int	rgb_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	color_floor(t_data *data, char *line)
{
	int	r;
	int	g;
	int	b;
	data->map.map = 0;

	r = 0;
	g = 0;
	b = 0;
	while (*line && !ft_isdigit(*line))
		line++;
	r = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while (!ft_isdigit(*line))
		line++;
	g = ft_atoi(line);
	while (!ft_isdigit(*line))
		line++;
	while (ft_isdigit(*line))
		line++;
	b = ft_atoi(line);
	data->map.f_color = rgb_color(r, g, b);
	printf("floor color = %x\n", data->map.f_color);
}

void	color_ceiling(t_data *data, char *line)
{
	int	r;
	int	g;
	int	b;
	data->map.map = 0;

	r = 0;
	g = 0;
	b = 0;
	while (*line && !ft_isdigit(*line))
		line++;
	r = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while (!ft_isdigit(*line))
		line++;
	g = ft_atoi(line);
	while (!ft_isdigit(*line))
		line++;
	while (ft_isdigit(*line))
		line++;
	b = ft_atoi(line);
	data->map.c_color = rgb_color(r, g, b);
}

// Check if floor and ceiling values are correct
// Create the color of the floor and ceiling with RGB
void	floor_and_ceiling_textures(t_data *data, char *line)
{
	if (line[0] == 'F' && line[1] == ' ')
		color_floor(data, line);
	else if (line[0] == 'C' && line[1] == ' ')
		color_ceiling(data, line);
    else
        exit_game("Error within floor and ceiling values", 1);
}
