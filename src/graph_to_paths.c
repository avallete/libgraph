/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_to_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:32:00 by avallete          #+#    #+#             */
/*   Updated: 2017/06/06 17:32:00 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libmatgraph.h"

static unsigned long	nb_paths(t_matrice_graph *graph, t_pathfind *pfind)
{
	unsigned long i;
	unsigned long nb_paths;

	nb_paths = 0;
	i = 1;
	while (i < graph->size)
	{
		if (graph->matrix[pfind->src][i])
			++nb_paths;
		++i;
	}
	return (nb_paths);
}

static unsigned long get_path_len(t_matrice_graph *graph, t_pathfind *pfind)
{
	unsigned long i;
	unsigned long e;
	unsigned long node;

	i = 0;
	node = pfind->src;
	while (node != pfind->dst)
	{
		e = 0;
		while (e < graph->size)
		{
			if (graph->matrix[node][e])
			{
				node = e;
				break;
			}
			++e;
		}
		++i;
	}
	return (i);
}

static t_path	*get_path_with_dfs(t_matrice_graph *graph, t_pathfind *pfind)
{
	t_path			*p;
	unsigned long	i;
	unsigned long	node;
	unsigned long	e;

	p = new_path(pfind->src, pfind->dst);
	p->len = get_path_len(graph, pfind);
	if ((p->path = (unsigned long*)malloc(sizeof(unsigned long) * p->len + 1)))
	{
		i = 0;
		node = pfind->src;
		while (node != pfind->dst)
		{
			p->path[i] = node;
			e = 0;
			while (e < graph->size)
			{
				if (graph->matrix[node][e] && unset_link(graph, node, e, 1))
				{
					node = e;
					break;
				}
				++e;
			}
			++i;
		}
		p->path[i] = node;
	}
	else
		delete_path(&p);
	return (p);
}

t_path					**graph_to_paths(t_matrice_graph *graph,
										   t_pathfind *pfind)
{
	t_path			**paths;
	unsigned long	i;
	unsigned long	total;

	i = 0;
	total = nb_paths(graph, pfind);
	if ((paths = (t_path**)malloc(sizeof(t_path*) * (total + 1))))
	{
		while (i < total)
		{
			paths[i] = get_path_with_dfs(graph, pfind);
			++i;
		}
		paths[i] = NULL;
		i = 0;
		while (i < total)
			add_path_to_graph(graph, paths[i++]);
	}
	return (paths);
}