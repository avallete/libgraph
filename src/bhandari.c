/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bhandari.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 22:28:00 by avallete          #+#    #+#             */
/*   Updated: 2017/06/05 22:28:00 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libmatgraph.h"

static void 	revert_path(t_matrice_graph *graph, t_path *path)
{
	unsigned long i;

	i = 0;
	while (i < path->len)
	{
		if (graph->matrix[path->path[i]][path->path[i + 1]] == 1)
		{
			graph->matrix[path->path[i]][path->path[i + 1]] = 0;
			graph->matrix[path->path[i + 1]][path->path[i]] = -1;
		}
		++i;
	}
}

static void 	find_disjoints_paths(t_matrice_graph *graph,
									t_matrice_graph *path_graph,
									t_pathfind *pfind,
									unsigned long max_paths)
{
	t_path			*path;
	unsigned long	i;

	i = 1;
	while (i < max_paths)
	{
		path = bellman_ford(graph, pfind);
		if (path)
		{
			add_path_to_graph(path_graph, path);
			revert_path(graph, path);
			delete_path(&path);
		}
		else
			break;
		++i;
	}
}

static void 	merge_paths(t_matrice_graph *graph,
									 t_matrice_graph *path_graph)
{
	unsigned long i;
	unsigned long e;

	i = 0;
	while (i < graph->size)
	{
		e = 0;
		while (e < graph->size)
		{
			if (graph->matrix[i][e] == -1 && path_graph->matrix[i][e] == 1)
				unset_link(path_graph, i, e, 0);
			++e;
		}
		++i;
	}
}


static void 	restore_reverted_links(t_matrice_graph *graph)
{
	unsigned long i;
	unsigned long e;

	i = 0;
	while (i < graph->size)
	{
		e = 0;
		while (e < graph->size)
		{
			if (graph->matrix[i][e] == -1)
			{
				graph->matrix[i][e] = 0;
				graph->matrix[e][i] = 1;
			}
			++e;
		}
		++i;
	}
}


t_matrice_graph			*bhandari(t_matrice_graph *graph, t_path *dijkstra_path,
							 t_pathfind *pfind, unsigned long max_paths)
{
	t_matrice_graph *path_graph;

	if ((path_graph = new_matrice_graph(graph->size)))
	{
		add_path_to_graph(path_graph, dijkstra_path);
		revert_path(graph, dijkstra_path);
		find_disjoints_paths(graph, path_graph, pfind, max_paths);
		merge_paths(graph, path_graph);
		restore_reverted_links(graph);
	}
	return (path_graph);
}