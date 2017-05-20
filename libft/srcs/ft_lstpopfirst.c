/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpopfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 13:44:55 by avallete          #+#    #+#             */
/*   Updated: 2017/04/29 14:07:12 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void    *ft_lstpopfirst(t_list **alst)
{
    void    *content;
    t_list  *head;

    content = NULL;
    if (alst && *alst)
    {
        content = (*alst)->content;
        head = *alst;
        *alst = (*alst)->next;
        free(head);
    }
    return (content);
}
