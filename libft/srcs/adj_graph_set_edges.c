/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adj_graph_set_edges.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 00:55:32 by avallete          #+#    #+#             */
/*   Updated: 2017/04/29 00:58:48 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

int     adj_graph_set_edges(t_adj_graph *graph, size_t node_index, char *data)
{
    if (node_index <= graph->size)
        return (-1);
    ft_memcpy(graph->matrix[node_index], data, graph->size);
    return (0);
}
