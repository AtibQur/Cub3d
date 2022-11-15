/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:39:59 by svan-ass          #+#    #+#             */
/*   Updated: 2022/02/09 12:40:00 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_nbrlen(int nbr)
{
	int	nbrlen;

	nbrlen = 0;
	if (nbr == 0)
		nbrlen = 1;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		nbrlen++;
	}
	while (nbr >= 1)
	{
		nbr = nbr / 10;
		nbrlen++;
	}
	return (nbrlen);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	len = ft_nbrlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[len] = '\0';
	len--;
	while (len >= 0 && n != 0)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (str);
}
