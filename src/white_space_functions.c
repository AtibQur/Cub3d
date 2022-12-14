/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   white_space_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:27:22 by hqureshi          #+#    #+#             */
/*   Updated: 2022/12/14 17:29:53 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\f' \
	|| c == '\n' || c == '\r');
}

char	*erase_whitespace(char *line)
{
	int		j;
	int		count;
	char	*new;

	new = ft_calloc(find_len_color(line) + 1, 1);
	if (!new)
		return (NULL);
	j = 0;
	count = 0;
	while (*line)
	{
		if (!ft_is_whitespace(*line))
		{
			new[j] = *line;
			j++;
		}
		if (*line == ',')
			count++;
		line++;
	}
	if (count >= 3)
		exit_game("Invalid values", 1);
	new[j] = '\0';
	return (new);
}

char	*skip_whitespace(char *line)
{
	while (ft_is_whitespace(*line))
		line++;
	return (line);
}
