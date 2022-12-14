/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floor_and_ceiling_textures.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hqureshi <hqureshi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 10:44:54 by hqureshi      #+#    #+#                 */
/*   Updated: 2022/12/14 17:14:12 by tvan-der      ########   odam.nl         */
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

bool    ft_is_whitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\n' || c == '\r');
}

int	find_len_color(char *line)
{
	int i;
	int count;

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

char *erase_whitespace(char *line)
{
	int j;
	int count;
	char *new;

	new = ft_calloc(find_len_color(line) + 1, 1);
	if (!new)
		return (NULL);
	j = 0;
	count = 0;
	while (*line)
	{
		if (!ft_is_whitespace(*line))
		{
			new[j] = *line;
			j++;
		}
		if (*line == ',')
			count++;
		line++;
	}
	if (count >= 3)
		exit_game("Invalid values", 1);
	new[j] = '\0';
	return (new);
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
void	floor_and_ceiling_textures(t_data *data, char *line)
{
	while (*line == ' ')
		line++;
	if (*line == 'F' && *(line + 1) == ' ')
		data->map.f_color = get_color(line);
	else if (*line == 'C' && *(line + 1) == ' ')
		data->map.c_color = get_color(line);
    else
        exit_game("Error within floor and ceiling values", 1);
}
