/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pathfind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:02:00 by avallete          #+#    #+#             */
/*   Updated: 2017/06/05 19:02:00 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libmatgraph.h"

t_pathfind	*new_pathfind(unsigned long src, unsigned long dst,
							unsigned long max_dist, unsigned long size)
{
	t_pathfind *pfind;

	pfind = NULL;
	if ((pfind = (t_pathfind*)malloc(sizeof(t_pathfind))))
	{
		pfind->parent = (int*)malloc(sizeof(int) * size);
		pfind->dist = (int*)malloc(sizeof(int) * size);
		pfind->visited = (bool*)malloc(sizeof(bool) * size);
		if (pfind->parent && pfind->dist && pfind->visited)
		{
			pfind->src = src;
			pfind->dst = dst;
			pfind->max_dist = max_dist;
		}
		else
			delete_pathfind(&pfind);
	}
	return (pfind);
}