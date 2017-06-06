/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path_to_graph.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 09:12:00 by avallete          #+#    #+#             */
/*   Updated: 2017/06/06 09:12:00 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libmatgraph.h"

void 	add_path_to_graph(t_matrice_graph *graph, t_path *path)
{
	unsigned long i;

	i = 0;
	while (i < path->len)
	{
		set_link(graph, path->path[i], path->path[i + 1], 1);
		++i;
	}
}