/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:23:21 by hqureshi          #+#    #+#             */
/*   Updated: 2022/12/14 10:23:37 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_map_chars(t_map *map, char c, int *k, int i)
{
	if (c == '\t')
	{
		map->map[i][*k] = ' ';
		map->map[i + 1][*k] = ' ';
		map->map[i + 2][*k] = ' ';
		map->map[i + 3][*k] = ' ';
		*k += 3;
	}
	else if (c == ' ' || c == '0' || c == '\n' || ft_isdigit(c))
		map->map[i][*k] = c;
	else if (c != 'N' || c != 'S' || c != 'W' || c != 'E')
		exit_game("Wrong map values", 1);
	*k += 1;
}

// add player in the map and also show direction depending on "NSWE"
int	add_player_pos(t_map *map, char c, int *k, int i)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		map->map[i][*k] = '0';
		map->player_dir = c;
		map->player_pos_x = *k + 0.5;
		map->player_pos_y = i + 0.5;
		*k += 1;
		return (1);
	}
	return (0);
}

// checks if player exists for direcitons "NSWE"
int	player_pos(t_data *data, char *line, int j)
{
	if (line[j] == 'N' || line[j] == 'S' || line[j] == 'W' || line[j] == 'E')
	{
		data->map.existing_player += 1;
		return (1);
	}
	return (0);
}
