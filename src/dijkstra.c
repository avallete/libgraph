/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 18:55:00 by avallete          #+#    #+#             */
/*   Updated: 2017/06/02 18:55:00 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/libmatgraph.h"

static int 		min_distance(t_matrice_graph *graph, int *dist, bool *visited)
{
	int		min_dist;
	int		min_index;
	size_t	i;

	min_dist = INT_MAX;
	min_index = 0;
	i = 0;
	while (i < graph->size)
	{
		if (visited[i] == 0 && dist[i] <= min_dist)
		{
			min_dist = dist[i];
			min_index = i;
		}
		++i;
	}
	return (min_index);
}

static	void 	init_dijkstra(const t_pathfind *pfind, const size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		pfind->parent[i] = -1;
		pfind->dist[i] = pfind->max_dist;
		pfind->visited[i] = false;
		++i;
	}
}

static	bool	check_and_compute_edge(t_matrice_graph *graph,
										 t_pathfind *pfind,
										 unsigned int min,
										 size_t v)
{
	if (!pfind->visited[v] && graph->matrix[min][v] &&
		pfind->dist[min] != pfind->max_dist &&
		pfind->dist[min] + graph->matrix[min][v] < pfind->dist[v])
	{
		pfind->parent[v] = min;
		pfind->dist[v] = pfind->dist[min] + graph->matrix[min][v];
		if (v == pfind->dst)
			return (true);
	}
	return (false);
}

static	bool 	found_path(t_matrice_graph *graph, t_pathfind *pfind)
{
	int		min;
	size_t	i;
	size_t 	v;
	size_t	end;

	i = 0;
	end = (graph->size - 1);
	while (i < end)
	{
		v = 0;
		min = min_distance(graph, pfind->dist, pfind->visited);
		pfind->visited[min] = true;
		while (v < graph->size)
		{
			if (check_and_compute_edge(graph, pfind, min, v))
				return (true);
			++v;
		}
		++i;
	}
	return (false);
}

/*
** Custom Dijkstra algorithm.
** Parameter:
** 		pfind: Contain utility variables to perform pathfinding.
**			->max_dist: The maximum len of searched path.
** 			->src: The source node where the algorithm start.
** 			->dst: The destination node that we want reach.
**
** Return:
** 			Return a t_path malloced object if a path shorter
**			than max_dist has been found between src and dst.
**
** 			Else return NULL.
*/
t_path 			*dijkstra(t_matrice_graph *graph, t_pathfind *pfind)
{
	t_path	*path;

	path = NULL;
	init_dijkstra(pfind, graph->size);
	pfind->dist[pfind->src] = 0;
	if (found_path(graph, pfind))
		path = pathfind_to_path(pfind);
	return (path);
}