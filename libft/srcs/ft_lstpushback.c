/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 12:30:47 by avallete          #+#    #+#             */
/*   Updated: 2017/04/29 23:13:37 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstpushback(t_list **alst, t_list *new)
{
	t_list *begin;

	begin = *alst;
    if (*alst == NULL)
        ft_lstadd(alst, new);
	else if (new)
	{
		while (begin->next != NULL)
			begin = begin->next;
		begin->next = new;
		new->next = NULL;
	}
}
