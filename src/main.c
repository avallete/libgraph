#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../libft/includes/libft.h"
#include "../includes/libmatgraph.h"

t_list *path;
t_matrice_graph *graph2;

void		print_matrix(t_matrice_graph *graph)
{
	unsigned long rowlen;
	unsigned int i;
	unsigned int e;

	i = 0;
	printf("Size: %lu\n", graph->size);
	printf("--  ");
	e = 0;
	while (e < graph->size)
	{
		printf("%-5d", (e % 99999));
		++e;
	}
	printf("\n");
	while (i < graph->size)
	{
		e = 0;
		printf("%-5d", (i % 99999));
		while (e < graph->size)
		{
			printf("%-5d", graph->matrix[i][e]);
			++e;
		}
		printf("\n");
		++i;
	}
}

int 	min_distance(t_matrice_graph *graph, int *dist, char *sptSet)
{
	int min = INT_MAX;
	int min_index = 0;

	for (int v = 0; v < graph->size; v++)
	{
		if (sptSet[v] == 0 && dist[v] <= min)
		{
			min = dist[v];
			min_index = v;
		}
	}
	return (min_index);
}

void printPath(t_matrice_graph *graph, int *parent, int j, int last)
{
	if (parent[j] == -1)
		return;
	ft_lstadd(&path, ft_lstnew(&j, sizeof(int)));
	printPath(graph, parent, parent[j], j);
	printf("%d ", j);
}

void invert_link(t_matrice_graph *graph, unsigned int src, unsigned int dst)
{
	if (dst < graph->size && src < graph->size)
	{
		if (graph->matrix[src][dst])
		{
			unset_link(graph, src, dst, 1);
			if (graph->matrix[dst][src])
				graph->matrix[dst][src] = 1;
			else
				graph->matrix[dst][src] = -1;
		}
	}
}

void revert_path(t_matrice_graph *graph, t_list *path)
{
	while (path->next)
	{
		invert_link(graph, (unsigned int) (*(int *) path->content),
					(unsigned int) (*(int *)
							path->next->content));
		path = path->next;
	}
}

void add_path_to_graph(t_list *path)
{
	unsigned int src;
	unsigned int dst;

	while (path->next)
	{
		src = (unsigned int) (*(int*)path->content);
		dst = (unsigned int) (*(int*)path->next->content);
		printf("\ntoggle: %d->%d :: %d\n", src, dst, graph2->matrix[src][dst]);
		set_link(graph2, src, dst, 1);
		path = path->next;
	}
}

void remove_inversed_edges(t_matrice_graph *graph)
{

	for (int i = 0; i < graph->size; i++)
	{
		for (int e = 0; e < graph->size; e++)
		{
			if (graph->matrix[i][e] == -1 && graph2->matrix[i][e] == 1)
			{
				graph2->matrix[i][e] = 0;
				graph2->matrix[e][i] = 0;
			}
		}
	}
}

void printSolution(t_matrice_graph *graph, int *dist, int src, int dst, int n,
				   int
		*parent)
{
	printf("Vertex\t  Distance\tPath");
	printf("\n%d -> %d :: ", src, dst);
	printPath(graph, parent, dst, src);
	ft_lstadd(&path, ft_lstnew(&src, sizeof(int)));
	revert_path(graph, path);
	add_path_to_graph(path);
}

void	restore_reverted_graph(t_matrice_graph *graph)
{
	for (int i = 0; i < graph->size; i++)
	{
		for (int e = 0; e < graph->size; e++)
		{
			if (graph->matrix[i][e] == -1)
			{
				graph->matrix[i][e] = 0;
//				graph->matrix[e][i] = 1;
			}
		}
	}
}

void 	dijkstra(t_matrice_graph *graph, unsigned int src, unsigned int dst)
{
	int 	u;
	int		dist[graph->size];
	int 	parent[graph->size];
	char	sptSet[graph->size];

	path = NULL;
	for (int i = 0; i < graph->size; i++)
	{
		parent[i] = -1;
		dist[i] = INT_MAX;
		sptSet[i] = 0;
	}
	dist[src] = 0;
	for (int count = 0; count < (graph->size - 1); count++)
	{
		u = min_distance(graph, dist, sptSet);
		sptSet[u] = 1;

		for (int v = 0; v < graph->size; v++)
		{
			if (sptSet[v] == 0 && graph->matrix[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph->matrix[u][v] < dist[v])
			{
				parent[v] = u;
				dist[v] = dist[u] + graph->matrix[u][v];
			}
			if (u == dst)
			{
				printSolution(graph, dist, src, dst, (int) graph->size, parent);
				return ;
			}
		}
	}
	printf("No path from %d to %d", src, dst);
}

static void     graph_iter(t_matrice_graph *graph, size_t *node,
						   t_list **stack)
{
	size_t i;

	i = 0;
	while (i < graph->size)
	{
		if (graph->matrix[*node][i])
			ft_lstadd(stack, ft_lstnew(&i, sizeof(unsigned int)));
		++i;
	}
}

void	dfs_print_paths(t_matrice_graph *graph, unsigned int src, unsigned int
dst)
{
	size_t *node = NULL;
	t_list *stack = NULL;

	stack = ft_lstnew(&src, sizeof(unsigned int));
	while (ft_lstsize(stack) > 0)
	{
		node = ft_lstpopfirst(&stack);
		printf("Node: %zu\n", *node);
		if (*node == dst)
		{
			printf("\n------------------------\n");
			if (ft_lstsize(stack) > 0)
				printf("Node: %zu\n", src);
		}
		graph_iter(graph, node, &stack);
		free(node);
		node = NULL;
	}
}

int main() {
	t_matrice_graph *graph;

//		 [1]----[2]
//		/        |
//	[0]-[4]-----[3]--[7]--|
//	  \    \   /     /    |
//	   \    [5]----[6]    |
//	    \                 |
//	     \                |
//	      [8]---------[9]-|

	graph = new_mat_graph(10);
	graph2 = new_mat_graph(10);
	set_link(graph, 0, 1, 1);
	set_link(graph, 0, 4, 1);
	set_link(graph, 0, 8, 1);
	set_link(graph, 1, 2, 1);
	set_link(graph, 2, 3, 1);
	set_link(graph, 3, 7, 1);
	set_link(graph, 4, 3, 1);
	set_link(graph, 4, 5, 1);
	set_link(graph, 5, 3, 1);
	set_link(graph, 5, 6, 1);
	set_link(graph, 6, 7, 1);
	set_link(graph, 8, 9, 1);
	set_link(graph, 9, 7, 1);
	dijkstra(graph, 0, 7);
	dijkstra(graph, 0, 7);
	dijkstra(graph, 0, 7);
	remove_inversed_edges(graph);
	print_matrix(graph2);
	dfs_print_paths(graph2, 0, 7);
	del_mat_graph(graph);
    return 0;
}
