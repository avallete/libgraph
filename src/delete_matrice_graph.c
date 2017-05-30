/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_matrice_graph.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 06:22:00 by avallete          #+#    #+#             */
/*   Updated: 2017/05/30 06:22:00 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libmatgraph.h"

void        delete_matrice_graph(t_matrice_graph *graph)
{
	unsigned long i;

	if (graph)
	{
		i = 0;
		if (graph->matrix)
		{
			while (i < graph->size)
			{
				if (graph->matrix[i])
					free(graph->matrix[i]);
				++i;
			}
			free(graph->matrix);
			graph->matrix = NULL;
		}
		free(graph);
		graph = NULL;
	}
}