/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:44:54 by hqureshi          #+#    #+#             */
/*   Updated: 2022/12/14 17:20:47 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Check with a loop if "NSWEFC" values are in the .cub file
// The .cub file always has these 6 values before the map
// or else the file is wrong and should not be used

void	check_elements(t_data *data, int fd)
{
	int		element_count;
	char	*line;
	char	*tmp;

	element_count = 0;
	line = get_next_line(fd);
	while (element_count < 6)
	{
		tmp = skip_whitespace(line);
		if (tmp && check_correct_values(tmp) == 1)
			exit_game("Map does not have the correct values", 1);
		else if (tmp && (*tmp == 'N' || *tmp == 'S'\
		|| *tmp == 'W' || *tmp == 'E'))
			element_count += save_wall_textures(data, tmp);
		else if (tmp && (*tmp == 'F' || *tmp == 'C'))
			element_count += floor_and_ceiling_textures(data, tmp);
		free(line);
		line = get_next_line(fd);
		if (!line)
			exit_game("File descriptor failed", 1);
		data->map.map_start += 1;
	}
	free(line);
}
