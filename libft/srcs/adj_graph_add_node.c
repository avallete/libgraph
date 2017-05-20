/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adj_graph_add_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 01:24:04 by avallete          #+#    #+#             */
/*   Updated: 2017/04/29 23:33:42 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/graph.h"

int     adj_graph_add_node(t_adj_graph *graph)
{
    char    **newmatrix;
    size_t  i;

    i = 0;
    newmatrix = NULL;
    if (!(newmatrix = (char**)malloc(sizeof(char*) * (graph->size + 1))))
        return (0);
    while (i < graph->size)
    {
        if (!(newmatrix[i] = (char*)malloc(sizeof(char) * (graph->size + 1))))
            return (0);        
        ft_memcpy(newmatrix[i], graph->matrix[i], graph->size);
        free(graph->matrix[i]);
        ++i;
    }
    if (!(newmatrix[i] = ft_strnew(graph->size + 1)))
        return (0);
    free(graph->matrix);
    graph->matrix = newmatrix;
    graph->size += 1;
    return (1);
}
