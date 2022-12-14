/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_correct_values.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:09:02 by hqureshi          #+#    #+#             */
/*   Updated: 2022/12/14 10:33:33 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Check for the first 6 loops if there are not any other values,
// if there are any other values, the map is wrong and should exit
int	check_correct_values(char *line)
{
	if (line[0] != 'N' && line[0] != 'S' && line[0] != 'W' && line[0] && \
	line[0] != 'E' && line[0] != 'F' && line[0] != 'C' && line[0] != '\n' && \
	line[0] != '\0')
		return (1);
	return (0);
}
