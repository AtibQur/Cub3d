/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_wall_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:59:11 by hqureshi          #+#    #+#             */
/*   Updated: 2022/12/14 10:27:51 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// skip first 2 indexes of path
// loop through the path until you don't hit a: |' '|, |'.'| and |'/'|
char	*ft_str_cpy(char *str, char *line)
{
	int	i;
	int	j;

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
	char	*str;

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
