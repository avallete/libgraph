/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 02:52:17 by avallete          #+#    #+#             */
/*   Updated: 2017/05/10 17:45:10 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H
#include "libft.h"

typedef struct   s_adj_graph
{
    size_t      size;
    char        **matrix;
}               t_adj_graph;

typedef struct  s_node
{

}               t_node;

typedef struct  s_edge
{

}               t_edge;

typedef struct  s_graph
{

}               t_graph;

t_adj_graph*    adj_graph_create(size_t size);
void            adj_graph_delete(t_adj_graph *graph);
int             adj_graph_add_node(t_adj_graph *graph);
int             adj_graph_set_edges(t_adj_graph *graph,\
                                        size_t node_index, char *data);
int             adj_graph_set_edge(t_adj_graph *graph, size_t src, \
                                        size_t dst, char oriented);
int             adj_graph_delete_edge(t_adj_graph *graph,\
                                        size_t src, size_t dst);
t_list        *adj_graph_shortests_paths_between(t_adj_graph *graph,\
                                                size_t src, size_t dst);
#endif
