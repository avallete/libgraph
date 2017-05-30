/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 09:14:00 by avallete          #+#    #+#             */
/*   Updated: 2017/05/30 09:14:00 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libmatgraph.h"

/*
** Function interverting (src) and (dst) into an directed graph.
** If the pair (dst, src) is already set, we invert the graph direction (with
** negative link value). (Useful for Bhandari algorithm).
**
** return values:
** 	-1: if an error occured (src or dst) out of the graph.
**	0: if a link (dst, src) already exist. And has been sucessfully negated.
**  1: if link (dst, src) didn't exist, and has been set.
*/

char invert_link(t_matrice_graph *graph, unsigned int src, unsigned int dst)
{
	if (dst < graph->size && src < graph->size)
	{
		if (graph->matrix[src][dst])
		{
			unset_link(graph, src, dst, 1);
			if (get_link(graph, dst, src))
			{
				if (negate_link(graph, dst, src, 1))
					return (0);
			}
			else
				 return (set_link(graph, dst, src, 1));
		}
	}
	return (-1);
}