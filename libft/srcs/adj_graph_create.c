/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_adj_graph.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:01:35 by avallete          #+#    #+#             */
/*   Updated: 2017/04/28 20:41:54 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graph.h"

t_adj_graph*    adj_graph_create(size_t size)
{
    t_adj_graph *ret;
    size_t      i;

    i = 0;
    ret = (t_adj_graph*)malloc(sizeof(t_adj_graph));
    ret->size = size;
    ret->matrix = (char**)malloc(sizeof(char*) * (size));
    while (i < size)
    {
        ret->matrix[i] = ft_strnew(ret->size);
        ++i;
    }
    return (ret);
}
