/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:31:29 by hqureshi          #+#    #+#             */
/*   Updated: 2022/12/14 17:41:04 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_map(t_data *data, t_map *map, char *line)
{
	int		k;

	k = 0;
	data->copy_map_j = 0;
	while (line[data->copy_map_j])
	{
		if (player_pos(data, line, data->copy_map_j))
			data->copy_map_j += add_player_pos(map, line[data->copy_map_j], \
			&k, data->copy_map_i);
		else
		{
			copy_map_chars(map, line[data->copy_map_j], &k, \
			data->copy_map_i);
			data->copy_map_j++;
		}
	}
}

void	read_map(t_data *data, t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	data->copy_map_i = 0;
	while (line)
	{
		copy_map(data, map, line);
		free(line);
		line = get_next_line(fd);
		data->copy_map_i++;
	}
	if (data->map.existing_player != 1)
		exit_game("Player is not correct", 1);
}

void	start_allocating(t_data *data, t_map *map)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(data->file_name, O_RDONLY);
	if (fd < 0)
		exit_game("Choose a correct map!", 1);
	data->map.map = calloc((data->map.height + 1), sizeof(char *));
	i = 0;
	while (i <= map->height)
	{
		data->map.map[i] = calloc((data->map.width + 1), sizeof(char));
		i++;
	}
	i = 0;
	while (i < map->map_start)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
	read_map(data, map, fd);
	close(fd);
}

void	start_parsing(t_data *data, t_map *map, int fd)
{
	char	*line;
	char	*tmp;

	line = get_next_line(fd);
	if (!line)
		exit_game("File descriptor failed", 1);
	while (line[0] == '\n' || line[0] == '\0')
	{
		tmp = line;
		line = get_next_line(fd);
		free(tmp);
		data->map.map_start += 1;
	}
	check_width_height(map, fd, line);
	close(fd);
	start_allocating(data, map);
}

void	parse_map(t_data *data)
{
	int	fd;

	fd = open(data->file_name, O_RDONLY);
	if (fd < 0)
		exit_game("Choose a correct map!", 1);
	check_cub_extension(data->file_name);
	check_elements(data, fd);
	start_parsing(data, &data->map, fd);
	check_walls(data);
}
