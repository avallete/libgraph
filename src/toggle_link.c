/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toogle_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 08:59:00 by avallete          #+#    #+#             */
/*   Updated: 2017/05/30 08:59:00 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libmatgraph.h"

char	toggle_link(t_matrice_graph *graph, unsigned int src,
					unsigned int dst, char oriented)
{
	if (dst < graph->size && src < graph->size)
	{
		if (graph->matrix[src][dst])
			graph->matrix[src][dst] = 0;
		else
			graph->matrix[src][dst] = 1;
		if (!oriented)
			toggle_link(graph, dst, src, 1);
		return (1);
	}
	return (-1);
}