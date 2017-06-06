/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfind_to_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 18:33:00 by avallete          #+#    #+#             */
/*   Updated: 2017/06/05 18:33:00 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libmatgraph.h"

static unsigned long	path_len(const t_pathfind *pfind)
{
	unsigned long current;
	unsigned long len;

	len = 0;
	current = pfind->dst;

	while (pfind->parent[current] != -1)
	{
		current = pfind->parent[current];
		++len;
	}
	return (len);
}

static	void 			set_path_from_parents(const t_pathfind *pfind,
												const t_path *path)
{
	unsigned long i;
	unsigned long current;

	current = path->dst;
	i = path->len;
	while (pfind->parent[current] != -1)
	{
		path->path[i] = current;
		current = pfind->parent[current];
		--i;
	}
	path->path[0] = path->src;
}

t_path					*pathfind_to_path(const t_pathfind *pfind)
{
	t_path			*path;
	unsigned long	len;

	path = NULL;
	len = path_len(pfind);
	if (len > 0 && (path = new_path(pfind->src, pfind->dst)))
	{
		path->len = len;
		path->path = (unsigned long*)malloc(sizeof(unsigned long) * path->len + 1);
		if (path->path)
			set_path_from_parents(pfind, path);
		else
			delete_path(&path);
	}
	return (path);
}