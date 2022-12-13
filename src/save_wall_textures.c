/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_wall_textures.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: hqureshi <hqureshi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 11:59:11 by hqureshi      #+#    #+#                 */
/*   Updated: 2022/12/13 15:31:04 by tvan-der      ########   odam.nl         */
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

// skip first 2 indexes of path
// loop through the path until you don't hit a: |' '|, |'.'| and |'/'|
char    *ft_str_cpy(char *str, char *line)
{
    int i;
    int j;

    i = 2;
    j = 0;
    while (line[i] == ' ' || line[i] == '.' || line[i] == '/')
        i++;
    while (line[i] != '\0')
    {
        str[j] = line[i];
        i++;
        j++;
    }
    return (str);
}

int	save_wall_textures(t_data *data, char *line)
{
    char    *str;

    str = calloc(ft_strlen(line) + 1, 1);
    str = ft_str_cpy(str, line);
    str[ft_strlen(str) - 1] = '\0';
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		no_wall(data, str);
    else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
        so_wall(data, str);
    else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
        we_wall(data, str);
    else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
        ea_wall(data, str);
	else
    {
        free(str);
		exit_game("Wrong wall texture values, please try again", 1);
    }
	return (1);
}
