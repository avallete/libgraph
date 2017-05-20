/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adj_graph_shortests_paths_between.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 01:38:33 by avallete          #+#    #+#             */
/*   Updated: 2017/05/05 07:20:50 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include <stdio.h>

void        ft_lstprint(t_list *lst)
{
    printf("\nList: ");
    printf("%d ", ((int)(*(size_t*)lst->content)));
    while (lst->next)
    {
        lst = lst->next;
        printf("%d ", ((int)(*(size_t*)lst->content)));
    }
    printf("\n");
}

static void     delete_node(void *content, size_t content_size)
{
    (void)content_size;
    free(content);
}    

static void     graph_iter(t_adj_graph *graph, size_t *visited, size_t *node, t_list **stack)
{
    size_t i;

    i = 0;
    while (i < graph->size)
    {
        if (graph->matrix[*node][i] && visited[i] == 0)
        {
            visited[i] = 1;
            ft_lstadd(stack, ft_lstnew(&i, sizeof(size_t)));
        }
        ++i;
    }
}

static int      free_memory(t_list *stack, size_t *visited, size_t *node, size_t dst)
{
    if (stack)
        ft_lstdel(&stack, delete_node);
    free(visited);
    if (node && *node == dst)
    {
        free(node);
        return (1);
    }
    return (0);
}

static int      get_path_between(t_adj_graph *graph, t_list **path, size_t src, size_t dst)
{
    size_t *node;
    size_t *visited;
    t_list *stack;

    visited = (size_t*)malloc(sizeof(size_t) * graph->size);
    stack = ft_lstnew(&src, sizeof(size_t));
    ft_bzero(visited, sizeof(size_t) * graph->size);
    visited[src] = 1;
    while (ft_lstsize(stack) > 0)
    {
        node = ft_lstpopfirst(&stack);
        ft_lstpushback(path, ft_lstnew(node, sizeof(size_t)));
        if (*node == dst)
            break;
        graph_iter(graph, visited, node, &stack);
        free(node);
        node = NULL;
    }
    return (free_memory(stack, visited, node, dst));
}

t_list        *adj_graph_get_shortest_path_between(t_adj_graph *graph, size_t src, size_t dst)
{
    t_list *path;

    path = NULL;
    if (get_path_between(graph, &path, src, dst))
        return (path);
    if (path)
        ft_lstdel(&path, delete_node);
    return (NULL);
}



t_list        *adj_graph_shortests_paths_between(t_adj_graph *graph,\
                                                size_t src, size_t dst)
{
    t_list *paths;
    t_list *path;
    size_t i;

    i = 0;
    paths = NULL;
    while (i < graph->size)
    {
        if (graph->matrix[src][i])
        {
            path = NULL;
            path = adj_graph_get_shortest_path_between(graph, i, dst);
            if (path)
            {
                printf("path: %p\n", path);
                ft_lstadd(&path, ft_lstnew(&src, sizeof(size_t)));
                ft_lstadd(&paths, ft_lstnew(path, sizeof(t_list)));
                free(path);
            }
        }
        ++i;
    }
    return (paths);
}
