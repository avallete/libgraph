#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "libft/includes/libft.h"

typedef struct      s_mat_graph
{
    unsigned long size;
    char            **matrix;
}                   t_mat_graph;

void        del_mat_graph(t_mat_graph *graph)
{
    unsigned long i;

    if (graph)
    {
        i = 0;
        if (graph->matrix)
        {
            while (i < graph->size)
            {
                if (graph->matrix[i])
                    free(graph->matrix[i]);
                ++i;
            }
            free(graph->matrix);
            graph->matrix = NULL;
        }
        free(graph);
        graph = NULL;
    }
}

void	ft_bzero(void *s, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)
        ((char*)s)[i++] = 0;
}

static void        init_matrix(t_mat_graph *graph)
{
    unsigned long   i;

    i = 0;
    while (i < graph->size)
    {
        if (!(graph->matrix[i] = (char*)malloc(sizeof(char) * graph->size)))
        {
            del_mat_graph(graph);
            break;
        }
        ft_bzero(graph->matrix[i], graph->size);
        ++i;
    }
}

void		print_matrix(t_mat_graph *graph)
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

char 	has_link(t_mat_graph *graph, unsigned int src, unsigned int dst)
{
	if (src < graph->size && dst < graph->size)
		return (graph->matrix[src][dst]);
	return (0);
}

void	set_link(t_mat_graph *graph, unsigned int src, unsigned int dst, char
oriented)
{
	if (dst < graph->size && src < graph->size)
	{
		graph->matrix[src][dst] = 1;
		if (!oriented)
			set_link(graph, dst, src, 1);
	}
}

void	unset_link(t_mat_graph *graph, unsigned int src, unsigned int dst, char
oriented)
{
	if (dst < graph->size && src < graph->size)
	{
		graph->matrix[src][dst] = 0;
		if (!oriented)
			set_link(graph, dst, src, 1);
	}
}


t_mat_graph *new_mat_graph(unsigned long size)
{
    t_mat_graph     *graph;

    graph = NULL;
    if (size > 0)
    {
        if ((graph = (t_mat_graph *)malloc(sizeof(t_mat_graph))))
        {
            graph->size = size;
            graph->matrix = NULL;
            if ((graph->matrix = (char**)malloc(sizeof(char*) * (size))))
				init_matrix(graph);
            else
                del_mat_graph(graph);
        }
    }
    return (graph);
}

int 	min_distance(t_mat_graph *graph, int *dist, char *sptSet)
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

void printPath(int *parent, int j)
{
	if (parent[j]==-1)
		return;

	printPath(parent, parent[j]);
	printf("%d ", j);
}

int printSolution(int *dist, int src, int dst, int n, int *parent)
{
	printf("Vertex\t  Distance\tPath");
	printf("\n%d -> %d :: ", src, dst);
	printPath(parent, dst);
}

void 	dijkstra(t_mat_graph *graph, unsigned int src, unsigned int dst)
{
	int 	u;
	int		dist[graph->size];
	int 	parent[graph->size];
	char	sptSet[graph->size];

	for (int i = 0; i < graph->size; i++)
	{
		parent[0] = -1;
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
				printSolution(dist, src, dst, (int) graph->size, parent);
				return ;
			}
		}
	}
	printf("No path from %d to %d", src, dst);
}

int main() {
	t_mat_graph *graph;

	graph = new_mat_graph(10);
	set_link(graph, 0, 3, 1);
	set_link(graph, 0, 1, 1);
	set_link(graph, 1, 2, 1);
	set_link(graph, 2, 4, 1);
	set_link(graph, 3, 4, 1);
	set_link(graph, 3, 6, 1);
	set_link(graph, 4, 5, 1);
	set_link(graph, 6, 4, 1);
	set_link(graph, 6, 7, 1);
	set_link(graph, 7, 5, 1);
	print_matrix(graph);
	dijkstra(graph, 0, 5);
	del_mat_graph(graph);
    return 0;
}
