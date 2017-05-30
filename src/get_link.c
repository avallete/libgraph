/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 06:52:00 by avallete          #+#    #+#             */
/*   Updated: 2017/05/30 06:52:00 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libmatgraph.h"

char 	get_link(t_matrice_graph *graph, unsigned int src, unsigned int dst)
{
	if (src < graph->size && dst < graph->size)
		return (graph->matrix[src][dst]);
	return (0);
}