/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:31:29 by hqureshi          #+#    #+#             */
/*   Updated: 2022/11/28 14:59:47 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    copy_map_chars(t_map *map, char c, int *k, int i)
{
    if (c == '\t')
    {
        map->map[i][*k] = ' ';
        map->map[i + 1][*k] = ' ';
        map->map[i + 2][*k] = ' ';
        map->map[i + 3][*k] = ' ';
        *k += 3;
    }
    else if (c == '0' || ft_isdigit(c) || c == ' ' || c == '\n')
        map->map[i][*k] = c;
    else if (c != 'N' && c != 'S' && c != 'W' && c != 'E')
        exit_game("Wrong map values", 1);
    *k += 1;
}

void    copy_map(t_data *data, t_map *map, int fd)
{
    int i;
    int j;
    int k;
    char *line;
    data->test = NULL;

    line = get_next_line(fd);
    i = 0;
    while (line) 
    {
        while (line[j])
        {
            j = 0;
            k = 0;
            copy_map_chars(map, line[j], &k, i);
            j++;
        }
        free(line);
        line = get_next_line(fd);
        i++;
    }
}

void    start_allocating(t_data *data, t_map *map)
{
    int     i;
    int     fd;
    
    fd = open(data->file_name, O_RDONLY);
    if (fd < 0)
        exit_game("Choose a correct map!", 1);
    data->map.map = calloc((data->map.height + 1), sizeof(char *));
    i = 0;
    while (i <= map->height)
    {
        data->map.map = calloc((data->map.width + 1), sizeof(char *));
        i++;
    }
    copy_map(data, map, fd);
}


void    start_parsing(t_data *data, t_map *map, int fd)
{
    char    *line;
    char    *tmp;
    
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

void    parse_map(t_data *data)
{
    int fd;

    fd = open(data->file_name, O_RDONLY);
    if (fd < 0)
        exit_game("Choose a correct map!", 1);
    check_cub_extension(data->file_name); // check extension name
    check_elements(data, fd); // check for elements and save values in map struct
    start_parsing(data, &data->map, fd);
}
