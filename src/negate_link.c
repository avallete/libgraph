/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negate_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 09:04:00 by avallete          #+#    #+#             */
/*   Updated: 2017/05/30 09:04:00 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libmatgraph.h"

char	negate_link(t_matrice_graph *graph, unsigned int src,
					unsigned int dst, char oriented)
{
	if (dst < graph->size && src < graph->size)
	{
		if (get_link(graph, src, dst) > 0)
			graph->matrix[src][dst] *= -1;
		if (!oriented)
			negate_link(graph, dst, src, 1);
		return (1);
	}
	return (-1);
}
