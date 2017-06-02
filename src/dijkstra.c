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

static	void 	init_dijkstra(const t_path *shortest_path, const size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		shortest_path->parent[i] = -1;
		shortest_path->dist[i] = shortest_path->max_dist;
		shortest_path->visited[i] = false;
		++i;
	}
}

static	bool	check_and_compute_edge(t_matrice_graph *graph,
										 t_path *path, unsigned int min, size_t v)
{
	if (!path->visited[v] && graph->matrix[min][v] &&
		path->dist[min] != path->max_dist &&
		path->dist[min] + graph->matrix[min][v] < path->dist[v])
	{
		path->parent[v] = min;
		path->dist[v] = path->dist[min] + graph->matrix[min][v];
		if (v == path->dst)
			return (true);
	}
	return (false);
}

static	bool 	found_path(t_matrice_graph *graph, t_path *path)
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
		min = min_distance(graph, path->dist, path->visited);
		path->visited[min] = true;
		while (v < graph->size)
		{
			if (check_and_compute_edge(graph, path, min, v))
				return (true);
			++v;
		}
		++i;
	}
	return (false);
}

void			printPath(t_matrice_graph *graph, int *parent, int j)
{
	if (parent[j] == -1)
		return;
	printPath(graph, parent, parent[j]);
	printf("%d ", j);
}

void 			dijkstra(t_matrice_graph *graph, unsigned int src,
						 unsigned int dst, int max_dist)
{
	t_path	shortest_path;

	shortest_path.len = 0;
	shortest_path.src = src;
	shortest_path.dst = dst;
	shortest_path.max_dist = max_dist;
	shortest_path.parent = (int*)malloc(sizeof(int) * graph->size);
	shortest_path.dist = (int*)malloc(sizeof(int) * graph->size);
	shortest_path.visited = (char*)malloc(sizeof(char) * graph->size);

	init_dijkstra(&shortest_path, graph->size);
	shortest_path.dist[src] = 0;
	if (found_path(graph, &shortest_path))
	{
		printf("path found !\n");
		printPath(graph, shortest_path.parent, dst);
		printf("------------\n");
	}
	else
		printf("No path smaller than %d from %d to %d\n", max_dist, src, dst);
}