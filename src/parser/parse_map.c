/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:31:29 by hqureshi          #+#    #+#             */
/*   Updated: 2022/11/29 17:41:25 by hqureshi         ###   ########.fr       */
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
    else if (c == ' ' || c == '0' || c == '\n' || ft_isdigit(c))
        map->map[i][*k] = c;
    *k += 1;
    printf("%c", c);
}

int add_player_pos(t_map *map, char c, int *k, int i)
{
    if (c == 'N')
    {
        map->map[i][*k] = c;
        *k += 1;
        return (1);
    }
    return (0);
}

// check with all sides
int player_pos(t_data *data, char *line, int j)
{
    if (line[j] == 'N')
    {
        data->map.existing_player = 1;
        return (1);
    }
    return (0);
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
        k = 0;
        j = 0;
        while (line[j])
        {
            if (player_pos(data, line, j))
                j += add_player_pos(map, line[j], &k, i);
            else 
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
    char    *line;
    
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
        free (line);
        i++;
    }
    copy_map(data, map, fd);
    close(fd);
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
