/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bellman_ford.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 08:21:00 by avallete          #+#    #+#             */
/*   Updated: 2017/06/04 08:21:00 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/libmatgraph.h"

/*
** Check if the graph contain a negative cycle.
*/
static bool	contain_negative_cycle(t_matrice_graph *graph, t_pathfind *path)
{
	size_t i;
	size_t e;

	i = 0;
	while (i < graph->size)
	{
		e = 0;
		while (e < graph->size)
		{
			if (graph->matrix[i][e] &&
					path->dist[i] != path->max_dist &&
					(path->dist[i] + graph->matrix[i][e]) < path->dist[e])
				return (true);
			++e;
		}
		++i;
	}
	return (false);
}

/*
** Init all necessary variables to perform the Bellman-Ford pathfinding.
*/
static void init_bellman_ford(const t_pathfind *shortest_path,
							  const size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		shortest_path->parent[i] = -1;
		shortest_path->dist[i] = shortest_path->max_dist;
		++i;
	}
}

/*
** Check, update and compute distance for all reacheables edges from node.
*/
static void check_and_compute_edges(t_matrice_graph *graph, t_pathfind *path,
									size_t node)
{
	size_t	v;

	v = 0;
	while (v < graph->size)
	{
		if (graph->matrix[node][v] &&
			path->dist[node] != path->max_dist &&
			(path->dist[node] + graph->matrix[node][v]) < path->dist[v])
		{
			path->parent[v] = node;
			path->dist[v] = (path->dist[node] + graph->matrix[node][v]);
		}
		++v;
	}
}

static bool	found_path_bellman(t_matrice_graph *graph, t_pathfind *path)
{
	size_t	i;
	size_t	u;
	size_t	end;

	i = 1;
	end = (graph->size - 1);
	while (i < end)
	{
		u = 0;
		while (u < graph->size)
		{
			check_and_compute_edges(graph, path, u);
			++u;
		}
		++i;
	}
	return (path->parent[path->dst] == -1 ? false : true);
}

t_path		*bellman_ford(t_matrice_graph *graph, t_pathfind *pfind)
{
	t_path		*path;

	path = NULL;
	init_bellman_ford(pfind, graph->size);
	pfind->dist[pfind->src] = 0;
	if (found_path_bellman(graph, pfind) &&
			!contain_negative_cycle(graph, pfind))
		path = pathfind_to_path(pfind);
	return (path);
}