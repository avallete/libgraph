/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adj_graph_set_edge.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 01:00:01 by avallete          #+#    #+#             */
/*   Updated: 2017/04/29 01:07:17 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

int     adj_graph_set_edge(t_adj_graph *graph, size_t src, \
                            size_t dst, char oriented)
{
    if (src >= graph->size || dst >= graph->size)
        return (-1);
    if (oriented)
        graph->matrix[src][dst] = 1;
    else
    {
        if (src != dst)
        {
            graph->matrix[src][dst] = 1;
            graph->matrix[dst][src] = 1;
        }
    }
    return (0);
}
