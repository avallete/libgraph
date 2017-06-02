/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgraph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 06:18:00 by avallete          #+#    #+#             */
/*   Updated: 2017/05/30 06:18:00 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGRAPH_LIBGRAPH_H
#define LIBGRAPH_LIBGRAPH_H
#define bool char
#define true 1
#define false 0
#include <stdlib.h>
#include <limits.h>

typedef struct			s_matrice_graph
{
	unsigned long		size;
	char				**matrix;
}						t_matrice_graph;

typedef struct			s_path
{
	unsigned long		len;
	unsigned long		src;
	unsigned long		dst;
	int					max_dist;
	int					*parent;
	int					*dist;
	bool				*visited;
}						t_path;

/*
** Constructors and Destructors
*/
t_matrice_graph			*new_matrice_graph(unsigned long size);
void					delete_matrice_graph(t_matrice_graph *graph);

/*
** Links managment for directed or indirected graph
*/
char					get_link(t_matrice_graph *graph, unsigned int src,
								 unsigned int dst);
char					set_link(t_matrice_graph *graph, unsigned int src,
								 unsigned int dst, char oriented);
char					unset_link(t_matrice_graph *graph, unsigned int src,
								   unsigned int dst, char oriented);
char					toggle_link(t_matrice_graph *graph, unsigned int src,
									unsigned int dst, char oriented);
char					negate_link(t_matrice_graph *graph, unsigned int src,
									unsigned int dst, char oriented);

/*
** Link managment for directed graph only
*/
char					invert_link(t_matrice_graph *graph, unsigned int src,
									unsigned int dst);


void					dijkstra(t_matrice_graph *graph, unsigned int src,
								 unsigned int dst, int max_dist);
#endif