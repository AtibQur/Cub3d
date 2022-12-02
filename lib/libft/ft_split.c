/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:40:26 by svan-ass          #+#    #+#             */
/*   Updated: 2022/11/25 16:56:38 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count(char *str, char c)
{
	int	i;
	int	count;
	int	word;

	i = 0;
	count = 0;
	word = 0;
	while (str[i] == c && str[i])
		i++;
	while (str[i])
	{
		if (str[i] != c && str[i])
			word = 1;
		if (str[i] == c)
		{
			while (str[i] == c && str[i])
				i++;
			if (str[i])
				count++;
		}
		else
			i++;
	}
	return (count + word);
}

static char	*ft_cpy(char *str, char chr)
{
	int		i;
	char	*array;

	i = 0;
	array = 0;
	while (str[i] == chr)
		i++;
	while (str[i] && str[i] != chr)
		i++;
	array = (char *)malloc(sizeof(char) * (i + 1));
	if (!array)
		return (0);
	i = 0;
	while (str[i] && str[i] != chr)
	{
		array[i] = str[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

static char	**ft_free(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		strings;
	char	**arr;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	strings = ft_count((char *)s, c);
	arr = ft_calloc(sizeof(char *), (strings + 1));
	if (!arr)
		return (0);
	while (i < strings)
	{
		while (s[0] == c)
			s++;
		arr[j] = ft_cpy((char *)s, c);
		if (!arr[j])
			return (ft_free(arr));
		j++;
		s = s + ft_strlen(arr[i]);
		i++;
	}
	return (arr);
}
