/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adj_graph_delete_edge.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 01:07:35 by avallete          #+#    #+#             */
/*   Updated: 2017/04/29 03:03:36 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

int         adj_graph_delete_edge(t_adj_graph *graph, size_t src, size_t dst)
{
    if (src >= graph->size || dst >= graph->size)
        return (-1);
    graph->matrix[src][dst] = 0;
    graph->matrix[dst][src] = 0;
    return (0);
}
