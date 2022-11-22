/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:04:05 by hqureshi          #+#    #+#             */
/*   Updated: 2022/11/22 15:08:11 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    check_cub_extension(char *file)
{
    size_t      length;
    const char* str;
    
    length = ft_strlen(file);
    str = &file[length-4];
    if (strncmp(str, ".cub", 4))
        exit_game("Use a file that uses .cub extension", 1);
}
