/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:44:54 by hqureshi          #+#    #+#             */
/*   Updated: 2022/11/28 11:40:40 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Check with a loop if "NSWEFC" values are in the .cub file
// The .cub file always has these 6 values before the map
// or else the file is wrong and should not be used
void    check_elements(t_data *data, int fd)
{
    char    *line;
	char	*tmp;
    int     element_count;

    element_count = 0;
    line = get_next_line(fd);
    while (element_count < 6)
    {
		if (check_correct_values(line) == 1)
			exit_game("Map does not have the correct values", 1);
    	else if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E')
			element_count += save_wall_textures(data, line);
		else if (line[0] == 'F' || line[0] == 'C')
		{
			floor_and_ceiling_textures(data, line);
			element_count++;
		}
		tmp = line;
    	line = get_next_line(fd);
		if (!line)
			exit_game("File descriptor failed", 1);
		free(tmp);
		data->map.map_start += 1;
	}
	free(line);
}
