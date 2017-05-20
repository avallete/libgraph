/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adj_graph_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 03:03:19 by avallete          #+#    #+#             */
/*   Updated: 2017/04/29 23:43:55 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void    adj_graph_delete(t_adj_graph *graph)
{
    size_t i;

    i = 0;
    while (i < graph->size)
    {
        free(graph->matrix[i]);
        ++i;
    }
    free(graph->matrix);
    free(graph);
}
