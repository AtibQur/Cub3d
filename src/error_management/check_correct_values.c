/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_correct_values.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hqureshi <hqureshi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 10:09:02 by hqureshi      #+#    #+#                 */
/*   Updated: 2022/12/14 14:42:04 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Check for the first 6 loops if there are not any other values,
// if there are any other values, the map is wrong and should exit
int	check_correct_values(char *line)
{
    // printf("line before = %s\n", line);
    while (*line == ' ')
        line++;
    // printf("line after = %s\n", line);
    if (*line != 'N' && *line != 'S' && *line != 'W' && *line &&\
    *line != 'E' && *line != 'F' && *line != 'C' && *line != '\n' && \
    *line != '\0')
        return (1);
    return (0);
}
