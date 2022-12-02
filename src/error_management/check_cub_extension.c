/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:38:10 by hqureshi          #+#    #+#             */
/*   Updated: 2022/12/02 16:18:21 by hqureshi         ###   ########.fr       */
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
