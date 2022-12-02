/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:47:26 by hqureshi          #+#    #+#             */
/*   Updated: 2022/12/02 15:42:50 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    check_wall_values(t_data *data, int i, int j)
{
    if (data->map.map[i][j] == '0')
    {
        if ((data->map.map[i][j - 1] != '1' && data->map.map[i][j - 1] != '0') || \
            (data->map.map[i][j + 1] != '1' && data->map.map[i][j + 1] != '0') || \
            (data->map.map[i + 1][j] != '1' && data->map.map[i + 1][j] != '0') || \
            (data->map.map[i - 1][j] != '1' && data->map.map[i - 1][j] != '0'))
            exit_game("Walls are not closed", 1);
        else
            return ;
    }
}

void    check_walls(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i <= data->map.height)
    {
        j = 0;
        while (data->map.map[i][j])
        {
            check_wall_values(data, i, j);
            j++;
        }
        i++;
    }
}
