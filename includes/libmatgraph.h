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

typedef struct			s_pathfind
{
	unsigned long		src;
	unsigned long		dst;
	int					max_dist;
	int					*parent;
	int					*dist;
	bool				*visited;
}						t_pathfind;

typedef struct 			s_path
{
	unsigned long		src;
	unsigned long		dst;
	unsigned long		len;
	unsigned long		*path;
}						t_path;

/*
** Constructors and Destructors
*/
t_matrice_graph			*new_matrice_graph(unsigned long size);
void					delete_matrice_graph(t_matrice_graph **graph);

/*
** Links management for directed or indirected graph
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
** Link management for directed graph only
*/
char					invert_link(t_matrice_graph *graph, unsigned int src,
									unsigned int dst);

/*
** Path management functions useful for pathfinding algorithmes
*/
t_path					*new_path(unsigned long src, unsigned long dst);
void 					delete_path(t_path **path);
t_pathfind				*new_pathfind(unsigned long src,
										unsigned long dst,
										unsigned long max_dist,
										unsigned long size);
void 					delete_pathfind(t_pathfind **pathfind);
t_path					*pathfind_to_path(const t_pathfind *pfind);
void					add_path_to_graph(t_matrice_graph *graph, t_path *path);
t_path					**graph_to_paths(t_matrice_graph *graph,
										   t_pathfind *pfind);

/*
** Pathfinding algorithmes
*/
t_path 					*dijkstra(t_matrice_graph *graph,
								   t_pathfind *pfind);
t_path					*bellman_ford(t_matrice_graph *graph,
										t_pathfind *pfind);
t_matrice_graph			*bhandari(t_matrice_graph *graph, t_path *dijkstra_path,
									 t_pathfind *pfind, unsigned long
									 max_paths);
#endif