/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:31:29 by hqureshi          #+#    #+#             */
/*   Updated: 2022/11/22 17:00:23 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void    check_element(t_data *data, int fd)
// {
// 	char	*line;
// 	char	*temp;
//     int     line_count;

//     line_count = 0;
// 	line = get_next_line(fd);
// 	check_line(line);
// 	while (line_count < 6)
// 	{
// 		if (elements_check(line))
// 			errorr("Error no valid path");
// 		else if (line[0] == 'N' || line[0] == 'S' \
// 		|| line[0] == 'E' || line[0] == 'W')
// 			line_count += safe_wall_textures(data, line);
// 		else if (line[0] == 'F' || line[0] == 'C')
// 		{
// 			check_floor_ceiling(data, line);
// 			line_count += 1;
// 		}
// 		temp = line;
// 		line = get_next_line(fd);
// 		check_line(line);
// 		free(temp);
// 		// data->start_map_line += 1;
// 	}
// 	double_check_map(data);
// 	free(line)
// }

// int	save_wall_texture(t_data *data, char *line)
// {

// }

// int	save_floor_ceiling(t_data *data, char *line)
// {
	
// }

void    check_elements(t_data *data, int fd)
{
    char    *line;
	char	*tmp;
    int     line_count;
    data->file.map = NULL;

    line_count = 0;
    line = get_next_line(fd);
    while (line_count < 6)
    {
    	if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E')
			// line_count += save_wall_texture(data, line);
			line_count++;
		else if (line[0] == 'F' || line[0] == 'C')
			// line_count += save_floor_ceiling(data, line);
			line_count++;
		tmp = line;
    	line = get_next_line(fd);
		free(tmp);
		printf("%d", line_count);
	}
	free(line);
	system("leaks cub3d");
}

void    parse_map(t_data *data, char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        exit_game("Choose a correct file!", 1);
    check_cub_extension(file);
    check_elements(data, fd);

}
