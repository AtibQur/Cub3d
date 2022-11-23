/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceiling_textures.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:44:54 by hqureshi          #+#    #+#             */
/*   Updated: 2022/11/23 14:32:31 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Check if floor and ceiling values are correct
// Create the color of the floor and ceiling with RGB
void	floor_and_ceiling_textures(t_data *data, char *line)
{
	data->file.map = NULL;
	if (line[0] == 'F' && line[1] == ' ')
		//color_floor
		printf("%s", line);
	else if (line[0] == 'C' && line[1] == ' ')
		//color_ceiling
		printf("%s", line);
    else
        exit_game("Error within floor and ceiling values", 1);
}