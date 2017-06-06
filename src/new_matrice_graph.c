/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_matrice_graph.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 06:28:00 by avallete          #+#    #+#             */
/*   Updated: 2017/05/30 06:28:00 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libmatgraph.h"

static void				bzero(void *s, size_t n)
{
	char *tmp;

	if (n)
	{
		tmp = s;
		while (n--)
			*(tmp++) = 0;
	}
}

static void				init_matrix(t_matrice_graph *graph)
{
	unsigned long   i;

	i = 0;
	while (i < graph->size)
	{
		if (!(graph->matrix[i] = (char*)malloc(sizeof(char) * graph->size)))
		{
			delete_matrice_graph(&graph);
			break;
		}
		bzero(graph->matrix[i], graph->size);
		++i;
	}
}

t_matrice_graph			*new_matrice_graph(unsigned long size)
{
	t_matrice_graph     *graph;

	graph = NULL;
	if (size > 0)
	{
		if ((graph = (t_matrice_graph *)malloc(sizeof(t_matrice_graph))))
		{
			graph->size = size;
			graph->matrix = NULL;
			if ((graph->matrix = (char**)malloc(sizeof(char*) * (size))))
				init_matrix(graph);
			else
				delete_matrice_graph(&graph);
		}
	}
	return (graph);
}