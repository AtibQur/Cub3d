/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_wall_textures.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: hqureshi <hqureshi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 11:59:11 by hqureshi      #+#    #+#                 */
/*   Updated: 2022/12/14 14:14:54 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	no_wall(t_data *data, char *str)
{
    data->texture.no_texture = mlx_load_png(str);
    if (data->texture.no_texture == 0)
    {
        printf("hi\n");
        exit_game("Wrong texture path.", 1);
    }
}

void	so_wall(t_data *data, char *str)
{
	data->texture.so_texture = mlx_load_png(str);
    if (data->texture.so_texture == 0)
    {
        printf("hi1\n");
        exit_game("Wrong texture path.", 1);
    }
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

char *ft_cpy_tex_path(char *line)
{
    char *path;
    
    line = skip_whitespace(line + 3);
    path = ft_calloc(ft_strlen(line) + 1, 1);
    if (!path)
        return (NULL);
    path = ft_str_cpy(path, line);
    path[ft_strlen(path) - 1] = '\0';
    return (path);
}

void load_texture(t_data *data, char *line)
{
    char    *str;
    
    str = NULL;
    str = ft_cpy_tex_path(line);
    if (!str)
        exit_game("Invalid texture path.", 1);
    if (!strncmp(line, "NO ", 3))
        no_wall(data, str);
    else if (!strncmp(line, "WE ", 3))
        we_wall(data, str);
    else if (!strncmp(line, "SO ", 3))
        so_wall(data, str);
    else if (!strncmp(line, "EA ", 3))
        ea_wall(data, str);
    free(str);
}


int	save_wall_textures(t_data *data, char *line)
{
	char    *str;
    
    str = NULL;
    if (*line == 'N' && *(line + 1) == 'O' && *(line + 2) == ' ')
        load_texture(data, line);
    else if (*line == 'S' && *(line + 1) == 'O' && *(line + 2) == ' ')
        load_texture(data, line);
    else if (*line == 'W' && *(line + 1) == 'E' && *(line + 2) == ' ')
        load_texture(data, line);
    else if (*line == 'E' && *(line + 1) == 'A' && *(line + 2) == ' ')
        load_texture(data, line);
	else
		exit_game("Wrong wall texture values, please try again", 1);
	return (1);
}
