/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <tvan-der@student.codam.nl>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/10 10:36:31 by Tessa         #+#    #+#                 */
/*   Updated: 2021/11/17 11:59:04 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_new_line(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

void	ft_strcpy(char *dst, char *src)
{
	int	i;

	if (!src)
		return ;
	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

int	ft_strcorrect(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			ft_strcpy(str, str + i + 1);
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		len_str1;
	int		len_str2;
	char	*new;

	if (!str2)
		return (str1);
	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	new = (char *)malloc(sizeof(char) * (len_str1 + len_str2 + 1 + 1));
	if (!new)
		return (NULL);
	ft_strcpy(new, str1);
	free(str1);
	i = 0;
	while (str2[i] != '\0' && i < len_str2 + 1)
	{
		new[len_str1] = str2[i];
		len_str1++;
		i++;
	}
	new[len_str1] = '\0';
	return (new);
}
