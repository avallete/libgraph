/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 11:11:07 by avallete          #+#    #+#             */
/*   Updated: 2017/04/29 14:06:41 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *list)
{
	t_list *begin;
	size_t i;

	if (list == NULL)
		return (0);
	begin = list;
	i = 1;
	while (begin->next)
	{
		begin = begin->next;
		++i;
	}
	return (i);
}
