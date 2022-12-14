/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width_height.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:45:08 by hqureshi          #+#    #+#             */
/*   Updated: 2022/12/14 10:39:56 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_map_length(char *line)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\t')
			ret += 3;
		i++;
		ret++;
	}
	return (ret);
}

void	check_width_height(t_map *map, int fd, char *line)
{
	int	height;
	int	max_width;
	int	width;

	height = 0;
	max_width = 0;
	while (line)
	{
		width = ft_map_length(line);
		if (width > max_width)
			max_width = width;
		free(line);
		line = get_next_line(fd);
		height++;
	}
	map->height = height;
	map->width = max_width;
}
