/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:40:30 by svan-ass          #+#    #+#             */
/*   Updated: 2022/02/09 12:40:31 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	n;

	n = (ft_strlen(s1) + 1);
	dst = malloc(n);
	if (!dst)
		return (0);
	ft_memcpy(dst, s1, n);
	return (dst);
}
