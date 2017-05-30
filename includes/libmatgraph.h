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

#include "libft.h"

typedef struct			s_matrice_graph
{
	unsigned long		size;
	char				**matrix;
}						t_matrice_graph;

/*
** Constructors and Destructors
*/
t_matrice_graph			*new_matrice_graph(unsigned long size);
void					delete_matrice_graph(t_matrice_graph *graph);
#endif