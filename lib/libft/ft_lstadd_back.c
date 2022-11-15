/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:40:01 by svan-ass          #+#    #+#             */
/*   Updated: 2022/02/09 12:40:02 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*new_last;

	if (lst)
	{
		if (*lst)
		{
			new_last = ft_lstlast(*lst);
			new_last->next = new;
		}
		else
			*lst = new;
	}
}
