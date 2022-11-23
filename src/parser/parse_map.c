/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:31:29 by hqureshi          #+#    #+#             */
/*   Updated: 2022/11/23 11:21:20 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    parse_map(t_data *data, char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        exit_game("Choose a correct file!", 1);
    check_cub_extension(file); // check extension name
    check_elements(data, fd); // check for elements and save values in file struct
}
